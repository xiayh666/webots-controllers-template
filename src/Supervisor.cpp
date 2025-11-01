#include "webots/Supervisor.hpp"
#include "common.hpp"
#include "webots/Emitter.hpp"
#include "webots/Keyboard.hpp"
#include "webots/Node.hpp"
#include "webots/Receiver.hpp"
#include <cmath>
#include <functional>
#include <string>
#include <Supervisor.hpp>
#include <vector>
using namespace Simulation;

Supervisor::Supervisor() {
    supervisor = new webots::Supervisor;
    timestep = supervisor->getBasicTimeStep();
    addReceiver("receiver");
}

Supervisor::~Supervisor() {
    delete supervisor;
}


webots::Emitter& Supervisor::addEmitter(std::string name) {
    emitter = supervisor->getEmitter(name);
    return *emitter;
}

webots::Emitter& Supervisor::getEmitter() {
    return *emitter;
}

webots::Receiver& Supervisor::addReceiver(std::string name) {
    auto receiver = supervisor->getReceiver(name);
    receiver->enable(timestep);
    receivers.push_back(receiver);
    return *receiver;
}

webots::Keyboard& Supervisor::addKeyboard() {
    keyboard = supervisor->getKeyboard();
    keyboard->enable(timestep);
    return *keyboard;
}

webots::Receiver& Supervisor::getReceiver(std::string name) {
    return *supervisor->getReceiver(name);
}


void Supervisor::mainloop(std::function<void(void)> main) {
    while(supervisor->step(timestep) != -1) {
        main();
    }

}


webots::Node* Supervisor::getNode(std::string DEF) {
    return supervisor->getFromDef(DEF);
}

void Supervisor::setVelocity(webots::Node* robot_node, double angle, double speed) {
  double velocity[6]{};
  velocity[0] = cos(angle) * speed; // vx
  velocity[1] = sin(angle) * speed; // vy

//   std::cout << "x:" << velocity[0] << " y:" << velocity[1] << std::endl;

  robot_node->setVelocity(velocity);
}


const DATA Supervisor::unpack() {
    auto receiver = getReceiver("receiver");
    auto data = *static_cast<const DATA*>(receiver.getData());
    receiver.nextPacket();
    return data;
}



webots::Keyboard& Supervisor::getKeyboard() {
    return *supervisor->getKeyboard();
}
