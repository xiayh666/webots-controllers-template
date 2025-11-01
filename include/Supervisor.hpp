#pragma once
#include "webots/Emitter.hpp"
#include "webots/Keyboard.hpp"
#include "webots/Node.hpp"
#include "webots/Receiver.hpp"
#include "webots/Supervisor.hpp"
#include <vector>
#include <webots/Robot.hpp>
#include <functional>
#include "common.hpp"

namespace Simulation {



class Supervisor{
private:
    std::vector<webots::Node*> nodes;
    std::vector<webots::Receiver*> receivers;
    webots::Keyboard* keyboard;
    webots::Emitter* emitter;


public:

    webots::Supervisor *supervisor;
    int timestep;

    webots::Emitter& addEmitter(std::string name);    
    webots::Receiver& addReceiver(std::string name);

    webots::Keyboard& addKeyboard();

    webots::Node* getNode(std::string DEF);

    webots::Emitter& getEmitter();

    webots::Receiver& getReceiver(std::string name);
    webots::Keyboard& getKeyboard();



    
    
    Supervisor();
    ~Supervisor();

    void mainloop(std::function<void(void)> main);
    void setVelocity(webots::Node* robot_node, double angle, double speed);

    const DATA receive();

};


} // namespace Simulation
