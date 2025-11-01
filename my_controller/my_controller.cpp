#include <Robot.hpp>
#include <cmath>
#include <common.hpp>
#include <cstddef>
#include <webots/Robot.hpp>
using namespace Simulation;

int main(int argc, char **argv) {
  // create the Robot instance.
  Robot robot = Robot();
  // auto m1 = robot.getMotor("left");
  // auto m2 = robot.getMotor("right");
  robot.addEmitter("emitter");
  robot.addLidar("lidar");

  // m1.setPosition(INFINITY);
  // m2.setPosition(INFINITY);
  // m1.setVelocity(0);
  // m2.setVelocity(0);

  DATA d{10 * 3.14 / 180, 0.5};

  auto mainTask = [&robot, &d]() {
    auto *pc = robot.getPointCloud();
    if (abs(pc->x) < INFINITY) {
      for (size_t i = 0; i < robot.getLidar().getNumberOfPoints(); i++) {
        std::cout << "x: " << pc->x << std::endl;
        std::cout << "y: " << pc->y << std::endl;
        std::cout << "z: " << pc->z << std::endl;
      }
    }

    // robot.send(d);
  };
  robot.mainloop(mainTask);

  return 0;
}
