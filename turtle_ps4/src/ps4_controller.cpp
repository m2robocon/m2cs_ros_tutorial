#include "rclcpp/rclcpp.hpp"

#include "geometry_msgs/msg/twist.hpp"
#include "m2_interfaces/msg/joy_data.hpp"
#include "std_srvs/srv/empty.hpp"
// Hints: some includes for the service are missing

class Ps4ControllerNode : public rclcpp::Node {
public:
    Ps4ControllerNode()
        : Node("ps4_controller_node")
    {
        // 1. create a subscriber here for subscribing PS4 data...
        sub_ = this->create_subscription<TodoMessageTypeHere>("TodoTopicNameHere", 10,
            [this](const m2_interfaces::msg::JoyData::SharedPtr msg) { ps4_callback(*msg); });

        // 2. create a publisher here for publishing turtle's velocity...
        pub_ = ...

        // 3. create a service client here for clear background...
        client_clear_ = this->create_client<TodoServiceTypeHere>("TodoServiceNameHere");

        // 4. create a service client here for change pen color...
        client_set_pen_ = ...
    }

private:
    void ps4_callback(const m2_interfaces::msg::JoyData& data)
    {
        // --- Requirement 1. Basic driving ---
        // TODO: 1.1 change level of "aggressiveness"


        // TODO: 1.2 calculate output velocity from input ps4 data, and publish it


        // --- Requirement 2. Clear background ---
        // TODO: detect a 'ps' button being pressed, and call corresponding service
        // Hint: to detect a button being pressed, you can the following logic (this is not the real code):
        //
        //      if ((data.button is pressed) and (old_data_.button not pressed)),
        //          then do sth...


        // --- Requirement 3. Change pen color ---
        // TODO: detect buttons being pressed, and call corresponding service
        // Hint: to detect a button being pressed, you can the following logic (this is not the real code):
        //
        //      if ((data.button is pressed) and (old_data_.button not pressed)),
        //          then do sth...


        // update old_data_ (You don't need to change this code)
        old_data_ = data;
    }

private:
    m2_interfaces::msg::JoyData old_data_;
    rclcpp::Subscription<m2_interfaces::msg::JoyData>::SharedPtr sub_;
    // TODO: add a publisher here for publishing turtle's velocity...
    rclcpp::Client<std_srvs::srv::Empty>::SharedPtr client_clear_;
    // TODO: add a service client here for changing turtle's pen color...
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Ps4ControllerNode>());
    rclcpp::shutdown();
    return 0;
}