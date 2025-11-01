#pragma once
#include "webots/Lidar.hpp"
#include "webots/Node.hpp"
#include "webots/Receiver.hpp"
#include "webots/Supervisor.hpp"
#include <unordered_map>
#include <webots/Robot.hpp>

namespace Simulation {
class WebotsSimulation {
private:
  // std::unique_ptr<webots::Supervisor> supervisor_;

  webots::Node* rootNode_;
  std::unordered_map<std::string, webots::Node*> robots_;


  int timeStep;

public:
  webots::Supervisor *supervisor_;
  webots::Receiver *receiver;
  WebotsSimulation() {};
  ~WebotsSimulation();
  void initSimulation();
  void mainloop();



  void addRobot(std::string DEF);
  webots::Node* getRobotRefByDEF(std::string DEF);
  webots::Receiver* getReceiver();


  const webots::LidarPoint* getPointCloud();

  void setVelocity(std::string DEF, double angle, double speed);
  void setVelocity(webots::Node *robot, double angle, double speed);

};
} // namespace Simulation