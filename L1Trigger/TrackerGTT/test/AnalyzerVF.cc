#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/interface/Run.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/Utilities/interface/EDGetToken.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/L1TrackTrigger/interface/L1Track.h"
#include "DataFormats/L1Trigger/interface/Vertex.h"

#include <vector>
#include <sstream>

using namespace std;
using namespace edm;
using namespace tt;
using namespace l1t;

namespace trackerGTT {

  /*! \class  trackerGTT::AnalyzerVF
   *  \brief  Class to analyze hardware like structured Vertex Collection used by L1Trigger emulators
   *  \author Thomas Schuh
   *  \date   2024, Aug
   */
  class AnalyzerVF : public one::EDAnalyzer<one::WatchRuns, one::SharedResources> {
  public:
    AnalyzerVF(const ParameterSet& iConfig);
    void beginJob() override {}
    void beginRun(const Run& iEvent, const EventSetup& iSetup) override {}
    void analyze(const Event& iEvent, const EventSetup& iSetup) override;
    void endRun(const Run& iEvent, const EventSetup& iSetup) override {}
    void endJob() override;

  private:
    // ED input token of Vertices
    EDGetTokenT<VertexCollection> getTokenVertex_;
    // enables analyze of TPs
    bool useMCTruth_;
    // printout
    stringstream log_;
  };

  AnalyzerVF::AnalyzerVF(const ParameterSet& iConfig) : useMCTruth_(iConfig.getParameter<bool>("UseMCTruth")) {
    usesResource("TFileService");
    // book in- and output ED products
    const string& label = iConfig.getParameter<string>("OutputLabelVF");
    const string& branch = iConfig.getParameter<string>("Branch");
    getTokenVertex_ = consumes<VertexCollection>(InputTag(label, branch));
    if (useMCTruth_) {
    }
    // log config
    log_.setf(ios::fixed, ios::floatfield);
    log_.precision(4);
  }

  void AnalyzerVF::analyze(const Event& iEvent, const EventSetup& iSetup) {
    // read in mc truth
    if (useMCTruth_) {
    }
    // read in vf product
    Handle<VertexCollection> handleVertex;
    iEvent.getByToken<VertexCollection>(getTokenVertex_, handleVertex);
  }

  void AnalyzerVF::endJob() {
    LogPrint("L1Trigger/TrackerGTT") << log_.str();
  }

}  // namespace trackerGTT

DEFINE_FWK_MODULE(trackerGTT::AnalyzerVF);