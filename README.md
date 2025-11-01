# webots-controllers-template

这是一个 webots 仿真软件的控制器模板，封装了如下功能：
- Robot 封装类
  - Motor
  - Lidar
  - Emitter
- Supervisor 封装类
  - Receiver
  - Emitter
  - Keyboard
 

对于上述的功能，提供了如下方法：
- Robot
  - addMotor(std::string name)
  - addEmitter(std::string name)
  - addLidar(std::string name)
  - getMotor(std::string name)
  - getEmitter(std::string name)
  - getLidar(std::string name)

  - setVelocity(double angle, double speed)
  - send(data)
  - getPointCloud()
 
- Supervisor
  - addEmitter(std::string name);    
  - addReceiver(std::string name);
  - addKeyboard();

  - getNode(std::string DEF);
  - getEmitter();
  - getReceiver(std::string name);
  - getKeyboard();
  - setVelocity(webots::Node* robot_node, double angle, double speed);
  - unpack();
