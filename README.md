# ENPM808X - Assignment : Gazebo Assignments

## Overview and Description

A roomba walker implementation in Gazebo

## License

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

## Author

Tharun V. Puthanveettil

## Assumptions
ROS2 Galactic package is created and tested on ubuntu 20.02 (Linux).
The colcon build is used for building the package.

## Dependencies
ROS2 Galactic has to be build and sourced

## To build the package

Open new terminal window and type the following:
```
mkdir ros2_ws/src
cd ros2_ws/src
git clone https://github.com/tvpian/beginner_tutorials.git
cd ..
source <path to ros2 setup>/install/setup.bash    
colcon build
source install/setup.bash
```
To end the process, type ctrl+C on all the terminal windows one by one.



## To run roomba - walker
To spawn turtlebot3 in the turtlebot world:  
```
ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py
```


Open a new terminal window and type:
```
cd ros2_ws
source <path to ros2 setup>/install/setup.bash    
source install/setup.bash 
ros2 launch src/launch/launch_roomba.py enable_recording:=True
```

    - output:
    ```
    Files:             rosbag_recording_0.db3
    Bag size:          7.1 GiB
    Storage id:        sqlite3
    Duration:          54.310s
    Start:             Dec  5 2022 23:39:45.776 (1670301585.776)
    End:               Dec  5 2022 23:40:40.87 (1670301640.87)
    Messages:          23135
    Topic information: Topic: /scan | Type: sensor_msgs/msg/LaserScan | Count: 259 | Serialization Format: cdr
                      Topic: /tf_static | Type: tf2_msgs/msg/TFMessage | Count: 1 | Serialization Format: cdr
                      Topic: /imu | Type: sensor_msgs/msg/Imu | Count: 10299 | Serialization Format: cdr
                      Topic: /odom | Type: nav_msgs/msg/Odometry | Count: 1538 | Serialization Format: cdr
                      Topic: /rosout | Type: rcl_interfaces/msg/Log | Count: 10 | Serialization Format: cdr
                      Topic: /robot_description | Type: std_msgs/msg/String | Count: 1 | Serialization Format: cdr
                      Topic: /clock | Type: rosgraph_msgs/msg/Clock | Count: 550 | Serialization Format: cdr
                      Topic: /tf | Type: tf2_msgs/msg/TFMessage | Count: 2542 | Serialization Format: cdr
                      Topic: /joint_states | Type: sensor_msgs/msg/JointState | Count: 1541 | Serialization Format: cdr
                      Topic: /performance_metrics | Type: gazebo_msgs/msg/PerformanceMetrics | Count: 266 | Serialization Format: cdr
                      Topic: /cmd_vel | Type: geometry_msgs/msg/Twist | Count: 3328 | Serialization Format: cdr
                      Topic: /parameter_events | Type: rcl_interfaces/msg/ParameterEvent | Count: 0 | Serialization Format: cdr
    ```
    
    Note: The above command runs the walker node and starts rosbag recording
    [Link to the rosbag output]( https://drive.google.com/drive/folders/13vFILeFBZj49pg3zcKc9cRHGrMtcTC79?usp=sharing)
   
- Assumptions
  - The version of ros2 used for the experiment is Galactic
