import FWCore.ParameterSet.Config as cms

TrackerGTTAnalyzer_params = cms.PSet (

  OutputLabelVF = cms.string( "ProducerVF" ), #
  UseMCTruth    = cms.bool( True )            # eneables analyze of TPs and TVs

)