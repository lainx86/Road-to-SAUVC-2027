#include "orchestrator/utils/mission_types.hpp"

OrchestratorMissionConfig load_orchestrator_mission_config(rclcpp::Node & node)
{
  OrchestratorMissionConfig config;
  node.declare_parameter("mission.main_run", config.main_run);
  node.declare_parameter<std::vector<std::string>>("mission.main_sequence", config.main_sequence);
  node.declare_parameter<std::vector<std::string>>("mission.qual_sequence", config.qual_sequence);

}

