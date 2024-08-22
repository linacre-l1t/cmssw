import FWCore.ParameterSet.Config as cms
from L1Trigger.TrackerGTT.Producer_cfi import TrackerGTTProducer_params
from L1Trigger.TrackerGTT.Analyzer_cfi import TrackerGTTAnalyzer_params

AnalyzerVF = cms.EDAnalyzer('trackerGTT::AnalyzerVF', TrackerGTTProducer_params, TrackerGTTAnalyzer_params)