#include "task_manager_test/TaskIdle.h"
using namespace task_manager_msgs;
using namespace task_manager_test;

TaskIndicator TaskIdle::configure(const TaskParameters & parameters) throw (InvalidParameter)
{
	debug("configuring...\n");
	return TaskStatus::TASK_CONFIGURED;
}

TaskIndicator TaskIdle::initialise(const TaskParameters & parameters) throw (InvalidParameter)
{
	debug("initialising...\n");
	return TaskStatus::TASK_INITIALISED;
}

TaskIndicator TaskIdle::iterate()
{
	debug("Idling...\n");
	return TaskStatus::TASK_RUNNING;
}

TaskIndicator TaskIdle::terminate()
{
	debug("terminating...\n");
	return TaskStatus::TASK_TERMINATED;
}


DYNAMIC_TASK(TaskIdle);