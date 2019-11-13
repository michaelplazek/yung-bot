# yung-bot
*Development of a driver for the IRobotCreate2*

Currently the driver has the ability to open the serial port, send byte commands, and read data packets from the serial port. ROS integration has begun and the next step is to develop ROS nodes for all of the stock sensors on the IRobot Create2. External sensors that will be integrated include an IMU and XBox Kinect for the ultimate purpose of effective SLAM mapping. 
The serial interface is done using termios and basic C system calls. C++ will be incorporated for the duration of the project.
