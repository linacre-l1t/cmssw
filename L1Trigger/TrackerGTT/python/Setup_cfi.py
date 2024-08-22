import FWCore.ParameterSet.Config as cms

TrackerGTTSetup_params = cms.PSet ( # GTT specific config parameter

  VF_params = cms.PSet (            # vertex finding specific config parameter
    NumBins = cms.int32( 256 ),     # number of bins along z-axis
  ),

)