import FWCore.ParameterSet.Config as cms
from L1Trigger.TrackerGTT.Producer_cfi import TrackerGTTProducer_params
from L1Trigger.TrackerGTT.Setup_cff import *

ProducerVF = cms.EDProducer('trackerGTT::ProducerVF', TrackerGTTProducer_params)