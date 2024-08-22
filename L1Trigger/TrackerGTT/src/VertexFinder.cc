#include "L1Trigger/TrackerGTT/interface/VertexFinder.h"

#include <vector>

using namespace std;
using namespace edm;
using namespace tt;
using namespace l1t;

namespace trackerGTT {

  VertexFinder::VertexFinder(const Setup* setup) : setup_(setup) {}

  // vertex finder emulation
  void VertexFinder::produce(const vector<L1Track>& tracks, vector<Vertex>& vertices) {
  }

}  // namespace trackerGTT
