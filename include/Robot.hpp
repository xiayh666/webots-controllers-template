#pragma once
#include "webots/Emitter.hpp"
#include "webots/Lidar.hpp"
#include "webots/Motor.hpp"
#include <vector>
#include <webots/Robot.hpp>
#include <functional>
#include "common.hpp"

namespace Simulation {



class Robot{
private:
    std::vector<webots::Motor*> motors;
    webots::Lidar *lidar;
    webots::Emitter* emitter; 

public:
    webots::Robot *robot;
    int timestep;



    webots::Motor& addMotor(std::string name);
    webots::Emitter& addEmitter(std::string name);
    webots::Lidar& addLidar(std::string name);

    
    webots::Motor& getMotor(std::string name);
    webots::Emitter& getEmitter();
    webots::Lidar& getLidar();


    
    
    Robot();
    ~Robot();

    void mainloop(std::function<void(void)> main);
    void setVelocity(double angle, double speed);

    void send(DATA data);
    const webots::LidarPoint* getPointCloud();

};


} // namespace Simulation
