#ifndef L1Trigger_TrackerGTT_VertexFinder_h
#define L1Trigger_TrackerGTT_VertexFinder_h

#include "DataFormats/L1TrackTrigger/interface/L1Track.h"
#include "DataFormats/L1Trigger/interface/Vertex.h"
#include "L1Trigger/TrackerGTT/interface/Setup.h"

#include <vector>

namespace trackerGTT {

  /*! \class  trackerDTC::VertexFinder
   *  \brief  GTT vertex finder emulator
   *  \author Thomas Schuh
   *  \date   2024, Aug
   */
  class VertexFinder {
  public:
    VertexFinder(const Setup* setup);
    ~VertexFinder() {}
    // vertex finder emulation
    void produce(const L1TrackCollection& tracks, l1t::VertexCollection& vertices);

  private:
    // class providing config parameter
    const Setup* setup_;
  };

}  // namespace trackerGTT

#endif