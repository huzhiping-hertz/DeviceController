#include "BaseTask.h"


BaseTask::BaseTask(string params,string taskName) :m_params(params), Task(taskName)
{
	
}
BaseTask::~BaseTask()
{
}


void BaseTask::runTask()
{
	Loger::Trace("run task");

}

void BaseTask::cancel()
{
	Poco::Task::cancel();
}
