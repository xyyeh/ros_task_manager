#ifndef TASK_WAIT_FOR_BUTTON_H
#define TASK_WAIT_FOR_BUTTON_H

#include "task_manager_lib/TaskDefinition.h"
#include "task_manager_turtlesim/TurtleSimEnv.h"
#include "task_manager_turtlesim/TaskWaitForButtonConfig.h"
#include "boost/algorithm/string.hpp"
#include "std_msgs/String.h"

using namespace task_manager_lib;

namespace task_manager_turtlesim {
    class TaskWaitForButton : public TaskDefinitionWithConfig<TaskWaitForButtonConfig,TaskWaitForButton>
    {

        protected:
            boost::shared_ptr<TurtleSimEnv> env;
            ros::Subscriber button_sub;
            std::set<std::string> expected_string;
            bool triggered;

            void buttonCallback(const std_msgs::String::ConstPtr& msg) {
                ROS_INFO("%p,Received text %s (%d string in set)",this,msg->data.c_str(),(int)expected_string.size());
                if (expected_string.find(boost::algorithm::to_lower_copy(msg->data)) != expected_string.end()) {
                    triggered = true;
                    ROS_INFO("%p: Triggered",this);
                }
            }

        public:
            TaskWaitForButton(boost::shared_ptr<TaskEnvironment> env); 
            virtual ~TaskWaitForButton() {};

            virtual TaskIndicator initialise(const TaskParameters & parameters) throw (InvalidParameter);

            virtual TaskIndicator iterate();

    };
};

#endif // TASK_WAIT_FOR_BUTTON_H
