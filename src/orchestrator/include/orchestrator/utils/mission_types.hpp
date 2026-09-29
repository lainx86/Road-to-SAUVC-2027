#ifndef ORCHESTRATOR__UTILS__MISSION_TYPES_HPP_
#define ORCHESTRATOR__UTILS__MISSION_TYPES_HPP_

#include <vector>
#include <queue>
#include <string>

#include "rclcpp/rclcpp.hpp"

struct mission_sequence
{
  std::string name;
  std::vector<std::string> sequence;
};

struct OrchestratorMissionConfig
{
  std::vector<Mission> missions_sequence = 
  {
    {
      "qualification",
      {
        "pass_gate",
        "turn_around",
        "pass_gate"
      }
    },
    {
      "Navigation",
      {
        "pass_gate",
        "dodge_flare"
      }
    },
    "Target_Acquisition",
    {
      "acquire_target",
      "drop"
    },
    {
      "Target_Reacquisition",
      {
        "pass_gate",
        "pickup_ball"
      }
    },
    {
      "ComLoc", //Communication and Localization
      {
        "localize",
        "bumpp_the_ball"
      }
    }
  }
  double setup_target_depth_m = 1.2;
  int setup_start_delay_s = 15;
};

OrchestratorMissionConfig orchestrator_load_mission(rclcpp::Node &node); 
std::queue<std::string> build_task_queue(const std::vector<std::string> & sequence);

#endif
