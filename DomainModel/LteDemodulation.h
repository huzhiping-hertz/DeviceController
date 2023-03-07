#ifndef LTEDEMODULATION_H
#define LTEDEMODULATION_H

#include "BaseTask.h"

using namespace RM;

namespace RM {

class LteDemodulation : public BaseTask {
 public:
  LteDemodulation(string params);
  ~LteDemodulation();
  void runTask();
};
}  // namespace RM
#endif
