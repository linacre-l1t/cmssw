#include "FWCore/Framework/interface/ESProducer.h"
#include "FWCore/Framework/interface/ModuleFactory.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "L1Trigger/TrackerGTT/interface/Setup.h"

#include <memory>

using namespace std;
using namespace edm;

namespace trackerGTT {

  /*! \class  trackerGTT::ProducerSetup
   *  \brief  Class to provide GTT specific config parameter
   *  \author Thomas Schuh
   *  \date   2024, Aug
   */
  class ProducerSetup : public ESProducer {
  public:
    ProducerSetup(const ParameterSet& iConfig) : iConfig_(iConfig) { setWhatProduced(this); }
    ~ProducerSetup() override {}
    unique_ptr<Setup> produce(const SetupRcd& rcd) { return make_unique<Setup>(iConfig_); }

  private:
    const ParameterSet iConfig_;
  };

}  // namespace trackerGTT

DEFINE_FWK_EVENTSETUP_MODULE(trackerGTT::ProducerSetup);