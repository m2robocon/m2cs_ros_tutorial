#include "rclcpp/rclcpp.hpp"

#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/srv/set_pen.hpp"
// hint: import your custom message and service here

#include <math.h>
#include <thread>

class PathManagerNode : public rclcpp::Node {
public:
    PathManagerNode()
        : Node("path_manager")
    {
        // 1. create a subscriber of turtle position here...
        // sub_ = this->create_subscription<>("", 10, std::bind(&PathManagerNode::cb_pose, this, std::placeholders::_1));

        // 2. create a publisher for turtle velocity here...
        // pub_ =

        // 3. create service server for cb_walk here...

        // 4. create service server for cb_orientation here...
    }

private:
    void cb_pose(const geometry_msgs::msg::Pose& data) { cur_pos_ = data; }

    // hint: use your custom made service type as function parameter type
    bool cb_walk(/* req */, /* res */)
    {
        if (req.distance < 0) {
            return false;
        }

        // hint: calculate the projected (x, y) after walking the distance,
        // and return false if it is outside the boundary

        while (/* goal not reached */)  // control loop here
        {
            // hint: in each iteration of the control loop, publish a velocity

            // hint: you need to use the formula for distance between two points

            // Sleep for 10 milliseconds to maintain 100 Hz
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    // hint: use your custom made service type as function parameter type
    bool cb_orientation(/* req */, /* res */)
    {
        // hint: calculate the projected (x, y) after walking the distance,
        // and return false if it is outside the boundary

        while (/* goal not reached */)  // control loop here
        {
            // hint: in each iteration of the control loop, publish a velocity

            // hint: signed smallest distance between two angles:
            // see https://stackoverflow.com/questions/1878907/the-smallest-difference-between-2-angles
            //     dist = fmod(req.orientation - cur_pos.theta + pi + 2 * pi, 2 * pi) - pi

            // Sleep for 10 milliseconds to maintain 100 Hz
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        // publish a velocity 0 at the end, to ensure the turtle really stops
        auto vel = geometry_msgs::msg::Twist();
        pub_->publish(vel);

        return true;
    }

private:
    geometry_msgs::msg::Pose cur_pos_;
    rclcpp::Subscription<geometry_msgs::msg::Pose>::SharedPtr sub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
    // hint: put your service servers here....
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PathManagerNode>());
    rclcpp::shutdown();
    return 0;
}
