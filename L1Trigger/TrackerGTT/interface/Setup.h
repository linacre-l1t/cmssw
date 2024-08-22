#ifndef L1Trigger_TrackerGTT_Setup_h
#define L1Trigger_TrackerGTT_Setup_h

#include "FWCore/Framework/interface/data_default_record_trait.h"
#include "L1Trigger/TrackerGTT/interface/SetupRcd.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include <vector>

namespace trackerGTT {

  /*! \class  trackerGTT::Setup
   *  \brief  Class to provide GTT specific config parameter
   *  \author Thomas Schuh
   *  \date   2024, Aug
   */
  class Setup {
  public:
    Setup() {}
    Setup(const edm::ParameterSet& iConfig);
    ~Setup() {}
    // nunmber of bins along z - axis
    int vfNumBins() const { return vfNumBins_; }

  private:
    // vertex finding specific config parameter
    edm::ParameterSet pSetVF_;
    // nunmber of bins along z - axis
    int vfNumBins_;
  };

}  // namespace trackerGTT

EVENTSETUP_DATA_DEFAULT_RECORD(trackerGTT::Setup, trackerGTT::SetupRcd);

#endif
