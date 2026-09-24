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
    
  }
}
