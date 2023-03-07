#ifndef BASETASK_H
#define BASETASK_H

#include "Poco/Task.h"
#include "Poco/TaskManager.h"
#include "Poco/TaskNotification.h"
#include "Poco/Observer.h"
#include "Poco/Timestamp.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/Format.h"
#include "Poco/String.h"
#include "nlohmann\json.hpp"

#include "CommonUtility/Loger.h"

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <vector>

using namespace std;
using json = nlohmann::json;
using Poco::DateTimeFormatter;
using Poco::DateTimeFormat;
using Poco::Timestamp;
using Poco::format;
using Poco::toLower;
using namespace RM;

namespace RM {

	class BaseTask:public Poco::Task 
	{

	public:
		BaseTask(string params,string taskName);
		virtual ~BaseTask();
		virtual void runTask();
		virtual void cancel();
	protected:
		string m_params;
	};
}
#endif 
