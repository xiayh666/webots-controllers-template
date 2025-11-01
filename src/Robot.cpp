#include "webots/Robot.hpp"
#include "common.hpp"
#include "webots/Emitter.hpp"
#include "webots/Lidar.hpp"
#include "webots/Motor.hpp"
#include <Robot.hpp>
#include <functional>
#include <string>

using namespace Simulation;

Robot::Robot() {
    robot = new webots::Robot;
    timestep = robot->getBasicTimeStep();
}

Robot::~Robot() {
    delete robot;
}

webots::Motor& Robot::addMotor(std::string name) {
    auto motor = robot->getMotor(name);
    motors.push_back(motor);
    return *motor;
}

webots::Emitter& Robot::addEmitter(std::string name) {
    emitter = robot->getEmitter(name);
    return *emitter;
}

webots::Lidar& Robot::addLidar(std::string name) {
    lidar = robot->getLidar(name);
    lidar->enable(timestep);
    lidar->enablePointCloud();
    return *lidar; 
}


webots::Emitter& Robot::getEmitter() {
    return *emitter;
}



webots::Motor& Robot::getMotor(std::string name) {
    return *robot->getMotor(name);

}

webots::Lidar& Robot::getLidar() {
    return *lidar;
}


void Robot::mainloop(std::function<void(void)> main) {
    while(robot->step(timestep) != -1) {
        main();
    }

}


void Robot::setVelocity(double angle, double speed) {
  double velocity[6]{};
  velocity[0] = cos(angle) * speed; // vx
  velocity[1] = sin(angle) * speed; // vy
//   robot->setVelocity(velocity);
}


void Robot::send(DATA data) {
    emitter->send(&data, sizeof(DATA*));
}

const webots::LidarPoint* Robot::getPointCloud() {
    return lidar->getPointCloud();
}


