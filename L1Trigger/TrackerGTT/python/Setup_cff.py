import FWCore.ParameterSet.Config as cms
from L1Trigger.TrackerGTT.Setup_cfi import TrackerGTTSetup_params

TrackerGTTSetup = cms.ESProducer("trackerGTT::ProducerSetup", TrackerGTTSetup_params)

fakeTrackerGTTSetupSource = cms.ESSource("EmptyESSource",
  recordName = cms.string('trackerGTT::SetupRcd'),
  iovIsRunNotTime = cms.bool(True),
  firstValid = cms.vuint32(1)
)
