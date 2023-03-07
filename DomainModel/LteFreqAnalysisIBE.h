#ifndef LTEFREQANALYSISIBE_H
#define LTEFREQANALYSISIBE_H

#include "BaseTask.h"

using namespace RM;

namespace RM {

	class LteFreqAnalysisIBE:public BaseTask
	{

	public:
		LteFreqAnalysisIBE(string params);
		~LteFreqAnalysisIBE();
		void runTask();
	};
}
#endif 
