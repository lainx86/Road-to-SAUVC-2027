#include "orchestrator/orchestrator.hpp"

#include <chrono>
#include <cmath>
#include <thread>
#include <future>

Orchestrator::Orchestrator(const std::string &name) : Node(name)
{
  mission_config_ = load_orchestrator_mission_config(*this);
  if (mission_config_.main_run)
  {
   RCLCPP_INFO(this->get_logger(), "Configured for MAIN ARENA mission sequence.");
  } else {
    RCLCPP_INFO(this->get_logger(), "Configured for QUALIFIER mission sequence.");
  }

  auto qos = rclcpp::QoS(10);
  callback_group_logic_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
  rclcpp::SubsrcriptionOptions sub_opts;
  sub_opts.callback_group = callback_group_logic_;
}
