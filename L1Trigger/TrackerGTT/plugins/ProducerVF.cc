#include "FWCore/Framework/interface/stream/EDProducer.h"
#include "FWCore/Framework/interface/Run.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Utilities/interface/EDGetToken.h"
#include "FWCore/Utilities/interface/ESGetToken.h"
#include "FWCore/Utilities/interface/EDPutToken.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Common/interface/Handle.h"

#include "DataFormats/L1TrackTrigger/interface/L1Track.h"
#include "DataFormats/L1Trigger/interface/Vertex.h"
#include "L1Trigger/TrackerGTT/interface/Setup.h"
#include "L1Trigger/TrackerGTT/interface/VertexFinder.h"

#include <numeric>
#include <string>

using namespace std;
using namespace edm;
using namespace tt;
using namespace l1t;

namespace trackerGTT {

  /*! \class  trackerGTT::ProducerVF
   *  \brief  GTT vertex finder emulator
   *  \author Thomas Schuh
   *  \date   2024, Aug
   */
  class ProducerVF : public stream::EDProducer<> {
  public:
    explicit ProducerVF(const ParameterSet&);
    ~ProducerVF() override {}

  private:
    void beginRun(const Run&, const EventSetup&) override;
    void produce(Event&, const EventSetup&) override;
    virtual void endJob() {}

    // ED input token of TTTracks
    EDGetTokenT<L1TrackCollection> edGetToken_;
    // ES input token of Setup
    ESGetToken<Setup, SetupRcd> esGetToken_;
    // ED output token for vertices
    EDPutTokenT<VertexCollection> edPutToken_;
    // cloass providing config paramater
    const Setup* setup_ = nullptr;
  };

  ProducerVF::ProducerVF(const ParameterSet& iConfig) {
    const InputTag& inputTag = iConfig.getParameter<InputTag>("InputTag");
    const string& branch = iConfig.getParameter<string>("Branch");
    // book in- and output ED products
    edGetToken_ = consumes<L1TrackCollection>(inputTag);
    edPutToken_ = produces<VertexCollection>(branch);
    // book ES product
    esGetToken_ = esConsumes<Setup, SetupRcd, Transition::BeginRun>();
  }

  void ProducerVF::beginRun(const Run& iRun, const EventSetup& iSetup) {
    setup_ = &iSetup.getData(esGetToken_);
  }

  void ProducerVF::produce(Event& iEvent, const EventSetup& iSetup) {
    // empty VF products
    VertexCollection vertices;
    // read in TFP Product
    Handle<L1TrackCollection> handle;
    iEvent.getByToken<L1TrackCollection>(edGetToken_, handle);
    // produce VF product
    VertexFinder vf(setup_);
    vf.produce(*handle.product(), vertices);
    // store products
    iEvent.emplace(edPutToken_, std::move(vertices));
  }

}  // namespace trackerGTT

DEFINE_FWK_MODULE(trackerGTT::ProducerVF);
