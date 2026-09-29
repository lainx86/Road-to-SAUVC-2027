#include "orchestsrator/utils/mission_types.hpp"

OrchestratorMissionConfig orchestsrator_load_mission(rclcpp::Node &node)
{
  OrchestratorMissionConfig config;
  node.declare_parameter(
      "setup.target_depth_m", config.setup_target_depth_m
      );
  
  node.declare_parameter(
      "setup.start_delay_s", config.start_delay_s
      );
}

