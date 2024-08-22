#include "L1Trigger/TrackerGTT/interface/Setup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

using namespace std;
using namespace edm;

namespace trackerGTT {

  Setup::Setup(const ParameterSet& iConfig)
      : pSetVF_(iConfig.getParameter<ParameterSet>("VF_params")),
        vfNumBins_(pSetVF_.getParameter<int>("NumBins")) {}

}  // namespace trackerGTT
