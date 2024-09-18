#include "rclcpp/rclcpp.hpp"

#include "geometry_msgs/msg/twist.hpp"
#include "m2_interfaces/msg/joy_data.hpp"
#include "turtlesim/srv/set_pen.hpp"
// hint: some imports may be missing

class Ps4ControllerNode : public rclcpp::Node {
public:
    Ps4ControllerNode()
        : Node("ps4_controller_node")
    {
        // 1. create a subscriber here...
        // sub_ = this->create_subscription<>("", 10, std::bind(&Ps4ControllerNode::callback, this, std::placeholders::_1));

        // 2. create a publisher here...
        // pub_ = ...

        // 3. create service clients here for SetPen and other services...
        // service_color_ = ...
    }

private:
    void callback(const m2_interfaces::msg::JoyData& data)
    {
        // 1. process received data and calculate output velocity
        // hint: to detect a button being pressed, you can the following logic:
        //
        // if ((data.button is pressed) and (old_data_.button not pressed)),
        //      then do sth...

        // 2. publish output velocity

        // 3. update old_data_
        old_data_ = data;
    }

private:
    m2_interfaces::msg::JoyData old_data_;
    rclcpp::Subscription<m2_interfaces::msg::JoyData>::SharedPtr sub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
    // hints: more service client objects here...
    // rclcpp::Service<...>::SharedPtr service_color_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Ps4ControllerNode>());
    rclcpp::shutdown();
    return 0;
}
