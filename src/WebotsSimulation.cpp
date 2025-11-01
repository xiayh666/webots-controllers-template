#include "webots/Receiver.hpp"
#include "webots/Supervisor.hpp"
#include <WebotsSimulation.hpp>
#include <cmath>
#include <utility>
#include <webots/Node.hpp>

namespace Simulation {

WebotsSimulation::~WebotsSimulation() { delete supervisor_; }

void WebotsSimulation::initSimulation() {

  supervisor_ = new webots::Supervisor;
  std::cout << "lidar init" << std::endl;
  receiver = supervisor_->getReceiver("receiver");
  // rootNode_ = supervisor_->getRoot();

  timeStep = (int)supervisor_->getBasicTimeStep();
}

void WebotsSimulation::mainloop() {

  // addRobot("ROBO");
  // webots::Node *robo = getRobotRefByDEF("ROBO");



  // auto pc = getPointCloud();
  // for (size_t i = 0; i < lidar->getNumberOfPoints(); i++) {
  //   std::cout << "pc->x:" << pc->x   << std::endl;
  //   std::cout << "pc->y:" << pc->y << std::endl;
  //   std::cout << "pc->z:" << pc->x  << std::endl;
  // }

  while (supervisor_->step(timeStep) != -1) {

    // setVelocity(robo, 60*3.14/180, 0.5);
  };
}

void WebotsSimulation::addRobot(std::string DEF) {
  if (robots_.find(DEF) != robots_.end()) {
    std::cerr << "robot " << DEF << " existed" << std::endl;
    return;
  }
  webots::Node *robot_node = supervisor_->getFromDef(DEF);
  robots_.insert({std::move(DEF), robot_node});
}

webots::Node *WebotsSimulation::getRobotRefByDEF(std::string DEF) {
  // return supervisor_->getFromDef(DEF);
  auto robot_node = robots_.find(DEF);
  if (robot_node == robots_.end()) {
    std::cerr  << "robot " << DEF << " not found" << std::endl;
    return nullptr;
  }

  return robot_node->second;

}

webots::Receiver* WebotsSimulation::getReceiver() {
  return receiver;
}

// const webots::LidarPoint* WebotsSimulation::getPointCloud() { 
//   return lidar->getPointCloud();

// }

void WebotsSimulation::setVelocity(std::string DEF, double angle,
                                   double speed) {
  webots::Node *robot = getRobotRefByDEF(DEF);
  setVelocity(robot, angle, speed);
}




void WebotsSimulation::setVelocity(webots::Node *robot, double angle,
                                   double speed) {
  double velocity[6]{};
  velocity[0] = cos(angle) * speed; // vx
  velocity[1] = sin(angle) * speed; // vy

  // std::cout << "vx:" <<cos(angle) * speed << std::endl; // vx
  // std::cout << "vy:" << sin(angle) * speed << std::endl; // vx

  robot->setVelocity(velocity);
}

} // namespace Simulation