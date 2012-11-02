//#line 2 "/opt/ros/electric/stacks/driver_common/dynamic_reconfigure/templates/ConfigType.h"
// *********************************************************
// 
// File autogenerated for the task_manager_turtlesim package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

/***********************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2008, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 ***********************************************************/

// Author: Blaise Gassend


#ifndef __task_manager_turtlesim__TASKSETPENCONFIG_H__
#define __task_manager_turtlesim__TASKSETPENCONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/config_init_mutex.h>

namespace task_manager_turtlesim
{
  class TaskSetPenConfigStatics;
  
  class TaskSetPenConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(TaskSetPenConfig &config, const TaskSetPenConfig &max, const TaskSetPenConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const TaskSetPenConfig &config1, const TaskSetPenConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, TaskSetPenConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const TaskSetPenConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, TaskSetPenConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const TaskSetPenConfig &config) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string name, std::string type, uint32_t level, 
          std::string description, std::string edit_method, T TaskSetPenConfig::* f) :
        AbstractParamDescription(name, type, level, description, edit_method),
        field(f)
      {}

      T (TaskSetPenConfig::* field);

      virtual void clamp(TaskSetPenConfig &config, const TaskSetPenConfig &max, const TaskSetPenConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const TaskSetPenConfig &config1, const TaskSetPenConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, TaskSetPenConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const TaskSetPenConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, TaskSetPenConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const TaskSetPenConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }
    };

//#line 12 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      std::string task_rename;
//#line 13 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      bool main_task;
//#line 14 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      double task_period;
//#line 15 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      double task_timeout;
//#line 12 "../cfg/TaskSetPen.cfg"
      int r;
//#line 13 "../cfg/TaskSetPen.cfg"
      int g;
//#line 14 "../cfg/TaskSetPen.cfg"
      int b;
//#line 15 "../cfg/TaskSetPen.cfg"
      int width;
//#line 16 "../cfg/TaskSetPen.cfg"
      bool on;
//#line 138 "/opt/ros/electric/stacks/driver_common/dynamic_reconfigure/templates/ConfigType.h"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        if ((*i)->fromMessage(msg, *this))
          count++;
      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("TaskSetPenConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->toMessage(msg, *this);
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      __toMessage__(msg, __param_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->fromServer(nh, *this);
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const TaskSetPenConfig &__max__ = __getMax__();
      const TaskSetPenConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const TaskSetPenConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const TaskSetPenConfig &__getDefault__();
    static const TaskSetPenConfig &__getMax__();
    static const TaskSetPenConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    
  private:
    static const TaskSetPenConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void TaskSetPenConfig::ParamDescription<std::string>::clamp(TaskSetPenConfig &config, const TaskSetPenConfig &max, const TaskSetPenConfig &min) const
  {
    return;
  }

  class TaskSetPenConfigStatics
  {
    friend class TaskSetPenConfig;
    
    TaskSetPenConfigStatics()
    {
//#line 12 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      __min__.task_rename = "";
//#line 12 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      __max__.task_rename = "";
//#line 12 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      __default__.task_rename = "";
//#line 12 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      __param_descriptions__.push_back(TaskSetPenConfig::AbstractParamDescriptionConstPtr(new TaskSetPenConfig::ParamDescription<std::string>("task_rename", "str", 0, "Task renaming at run-time", "", &TaskSetPenConfig::task_rename)));
//#line 13 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      __min__.main_task = 0;
//#line 13 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      __max__.main_task = 1;
//#line 13 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      __default__.main_task = 1;
//#line 13 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      __param_descriptions__.push_back(TaskSetPenConfig::AbstractParamDescriptionConstPtr(new TaskSetPenConfig::ParamDescription<bool>("main_task", "bool", 0, "Task running in foreground", "", &TaskSetPenConfig::main_task)));
//#line 14 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      __min__.task_period = -std::numeric_limits<double>::infinity();
//#line 14 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      __max__.task_period = std::numeric_limits<double>::infinity();
//#line 14 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      __default__.task_period = -1.0;
//#line 14 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      __param_descriptions__.push_back(TaskSetPenConfig::AbstractParamDescriptionConstPtr(new TaskSetPenConfig::ParamDescription<double>("task_period", "double", 0, "Task period", "", &TaskSetPenConfig::task_period)));
//#line 15 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      __min__.task_timeout = -std::numeric_limits<double>::infinity();
//#line 15 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      __max__.task_timeout = std::numeric_limits<double>::infinity();
//#line 15 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      __default__.task_timeout = -1.0;
//#line 15 "/data/my_ros/ros_task_manager/task_manager_lib/src/task_manager_lib/parameter_generator.py"
      __param_descriptions__.push_back(TaskSetPenConfig::AbstractParamDescriptionConstPtr(new TaskSetPenConfig::ParamDescription<double>("task_timeout", "double", 0, "Task timeout", "", &TaskSetPenConfig::task_timeout)));
//#line 12 "../cfg/TaskSetPen.cfg"
      __min__.r = 0;
//#line 12 "../cfg/TaskSetPen.cfg"
      __max__.r = 255;
//#line 12 "../cfg/TaskSetPen.cfg"
      __default__.r = 128;
//#line 12 "../cfg/TaskSetPen.cfg"
      __param_descriptions__.push_back(TaskSetPenConfig::AbstractParamDescriptionConstPtr(new TaskSetPenConfig::ParamDescription<int>("r", "int", 0, "Red component", "", &TaskSetPenConfig::r)));
//#line 13 "../cfg/TaskSetPen.cfg"
      __min__.g = 0;
//#line 13 "../cfg/TaskSetPen.cfg"
      __max__.g = 255;
//#line 13 "../cfg/TaskSetPen.cfg"
      __default__.g = 128;
//#line 13 "../cfg/TaskSetPen.cfg"
      __param_descriptions__.push_back(TaskSetPenConfig::AbstractParamDescriptionConstPtr(new TaskSetPenConfig::ParamDescription<int>("g", "int", 0, "Green component", "", &TaskSetPenConfig::g)));
//#line 14 "../cfg/TaskSetPen.cfg"
      __min__.b = 0;
//#line 14 "../cfg/TaskSetPen.cfg"
      __max__.b = 255;
//#line 14 "../cfg/TaskSetPen.cfg"
      __default__.b = 128;
//#line 14 "../cfg/TaskSetPen.cfg"
      __param_descriptions__.push_back(TaskSetPenConfig::AbstractParamDescriptionConstPtr(new TaskSetPenConfig::ParamDescription<int>("b", "int", 0, "Blue component", "", &TaskSetPenConfig::b)));
//#line 15 "../cfg/TaskSetPen.cfg"
      __min__.width = 1;
//#line 15 "../cfg/TaskSetPen.cfg"
      __max__.width = 10;
//#line 15 "../cfg/TaskSetPen.cfg"
      __default__.width = 1;
//#line 15 "../cfg/TaskSetPen.cfg"
      __param_descriptions__.push_back(TaskSetPenConfig::AbstractParamDescriptionConstPtr(new TaskSetPenConfig::ParamDescription<int>("width", "int", 0, "Line width", "", &TaskSetPenConfig::width)));
//#line 16 "../cfg/TaskSetPen.cfg"
      __min__.on = 0;
//#line 16 "../cfg/TaskSetPen.cfg"
      __max__.on = 1;
//#line 16 "../cfg/TaskSetPen.cfg"
      __default__.on = 1;
//#line 16 "../cfg/TaskSetPen.cfg"
      __param_descriptions__.push_back(TaskSetPenConfig::AbstractParamDescriptionConstPtr(new TaskSetPenConfig::ParamDescription<bool>("on", "bool", 0, "Activate pen", "", &TaskSetPenConfig::on)));
//#line 239 "/opt/ros/electric/stacks/driver_common/dynamic_reconfigure/templates/ConfigType.h"
    
      for (std::vector<TaskSetPenConfig::AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        __description_message__.parameters.push_back(**i);
      __max__.__toMessage__(__description_message__.max, __param_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__); 
    }
    std::vector<TaskSetPenConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    TaskSetPenConfig __max__;
    TaskSetPenConfig __min__;
    TaskSetPenConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;
    static const TaskSetPenConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static TaskSetPenConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &TaskSetPenConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const TaskSetPenConfig &TaskSetPenConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const TaskSetPenConfig &TaskSetPenConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const TaskSetPenConfig &TaskSetPenConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<TaskSetPenConfig::AbstractParamDescriptionConstPtr> &TaskSetPenConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const TaskSetPenConfigStatics *TaskSetPenConfig::__get_statics__()
  {
    const static TaskSetPenConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = TaskSetPenConfigStatics::get_instance();
    
    return statics;
  }


}

#endif // __TASKSETPENRECONFIGURATOR_H__
