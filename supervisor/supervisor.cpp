#include "common.hpp"
#include "webots/Keyboard.hpp"
#include <Supervisor.hpp>
#include <WebotsSimulation.hpp>
using namespace Simulation;

// All the webots classes are defined in the "webots" namespace

int main(int argc, char **argv) {

  // Simulation::WebotsSimulation sim;
  // sim.initSimulation();
  // sim.addRobot("ROBO");

  // sim.setVelocity("ROBO", 0, 0.5);
  // sim.mainloop();
  Simulation::Supervisor supervisor;
  supervisor.addReceiver("receiver");

  auto r1 = supervisor.getNode("ROBO");
  auto keyboard = supervisor.addKeyboard();

  supervisor.mainloop([&supervisor, &keyboard, &r1]() {
    auto receiver = supervisor.getReceiver("receiver");
    DATA data;

    int key = keyboard.getKey();
    constexpr double speed = 1;
    if (key == 'W') {
      data = {0, speed};
    }
    if (key == 'S') {
      data = {180 * 3.14 / 180, speed};
    }
    if (key == 'A') {
      data = {-90 * 3.14 / 180, -speed};
    }
    if (key == 'D') {
      data = {90 * 3.14 / 180, -speed};
    }
    if (receiver.getQueueLength() > 0) {
      data = supervisor.receive();
    }

    supervisor.setVelocity(r1, data.x, data.y);
  });

  return 0;
}
