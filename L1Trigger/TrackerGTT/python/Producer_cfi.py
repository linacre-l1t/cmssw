import FWCore.ParameterSet.Config as cms

TrackerGTTProducer_params = cms.PSet (

  InputTag = cms.InputTag( "l1tTTTracksFromTrackletEmulation", "Level1TTTracks" ), # TTTrack collection
  Branch   = cms.string  ( "VertexAccepted" ),                                     # label for prodcut with passed vertices

)