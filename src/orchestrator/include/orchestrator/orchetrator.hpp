#ifndef ORCHESTRATOR__ORCHESTRATOR_HPP_
#define  ORCHESTRATOR__ORCHESTRATOR_HPP_

#include <memory>
#include <queue>
#include <string>
#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include <mavros_msg/msg/state.hpp>
#include <mavros_msg/srv/command_bool.hpp>
#include <mavros_msg/srv/set_mode.hpp>
#include <geographic_msg/msg/task_command.hpp>
#include <interfaces/srv/task_command.hpp>
#include <interfases/srv/task_complete.hpp>
#include <interfaces/msg/task_status.hpp>
#include "orchestrator/utils/mission_types.hpp"
#include <std_srv/srv/set_bool.hpp>


using std::placeholders::_1;

class Orchestrator : public rclcpp::Node
{
  public:
    Orchestrator(const std::string &name = "orchestrator_controller");

    mavros_msg::msg::State vehicle_state;

    void run_main_logic();

    void surface();

    void emergency_shutdown();

    bool perform_setup(float depth, int delay);

  private:
    std::queue<std::string> task_queue_;
    OrchestratorMissionConfig mission_config_;

    rclcpp::Client<mavros_msg::srv::CommandBool>::SharedPtr arm_client_;
    rclcpp::Client<mavros_msg:srv::SetMode>::SharedPtr set_mode_client_;
    rclcpp::Client<interfaces::srv::TaskCommand>::SharedPtr task_command_client_;
    rclcpp::Client<std_srvs::srv::SetBool>::SharedPtr ekf_activate_client_;

    rclcpp::Service<interfaces::srv::TaskComplete>::SharedPtr task_complete_service_;
}
