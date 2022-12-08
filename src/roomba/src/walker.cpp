//  "Copyright[2022] by Tharun V. Puthanveettil"
#include <chrono>
#include <functional>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
using namespace std::chrono_literals;
using std::placeholders::_1;



class roomba : public rclcpp::Node {
 public:
  roomba();

 private:
  void move();
  void detectObstacles(const sensor_msgs::msg::LaserScan::SharedPtr msg);
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscriber_;
  geometry_msgs::msg::Twist commandVelocity;
  bool obstacleFound;
};

roomba::roomba() : Node("roomba_walker"), obstacleFound(false) {
  auto sensor_qos = rclcpp::QoS(rclcpp::SensorDataQoS());
  publisher_ =
      this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
  timer_ = this->create_wall_timer(100ms, std::bind(&roomba::move, this));
  subscriber_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
      "/scan", sensor_qos, std::bind(&roomba::detectObstacles, this, _1));
}

void roomba::move() {
  if (obstacleFound) {
    commandVelocity.linear.x = 0.0;
    commandVelocity.angular.z = 0.4;
  } else {
    commandVelocity.linear.x = 0.1;
    commandVelocity.angular.z = 0.0;
  }
  publisher_->publish(commandVelocity);
}

void roomba::detectObstacles(const sensor_msgs::msg::LaserScan::SharedPtr msg) {
  obstacleFound = false;
  float range;
  for (int i = 0; i < 50; i++) {
    range = msg->ranges[i];
    if (range < 0.3) {
      obstacleFound = true;
      break;
    }
  }
  for (int i = 290; i < 359; i++) {
    range = msg->ranges[i];
    if (range < 0.3) {
      obstacleFound = true;
      break;
    }
  }
}

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<roomba>());
  rclcpp::shutdown();
  return 0;
}

