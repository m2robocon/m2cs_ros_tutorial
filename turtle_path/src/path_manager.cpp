#include "rclcpp/rclcpp.hpp"

#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"
// Hints: some includes for the service are missing

#include <math.h>

using namespace std::chrono_literals;

class PathManagerNode : public rclcpp::Node {
public:
    PathManagerNode()
        : Node("path_manager")
    {
        // 1. create a subscriber of turtle position here...
        sub_ = this->create_subscription<TodoMessageTypeHere>("TodoTopicNameHere", 10,
            [this](const turtlesim::msg::Pose::SharedPtr msg) { cb_pose(*msg); });

        // 2. create a publisher for turtle velocity here...
        pub_ = ...

        // 3. create service server for set_orientation_cb here...
        set_orientation_srv_ =
            this->create_service<TodoServiceTypeHere>("TodoServiceNameHere",
                [this](const std::shared_ptr<TodoServiceRequestTypeHere> req,
                    std::shared_ptr<TodoServiceResponseTypeHere> resp) {
                    set_orientation_cb(req, resp);
                });

        // 4. create service server for walk_distance_cb here...
        walk_distance_srv_ = ...

        // set up a 100 hz loop for running time-consuming work
        timer_ = create_wall_timer(10ms, [this]() { do_tick(); });
    }

private:
    void cb_pose(const turtlesim::msg::Pose& data) { 
        // save the latest turtle's pose
        cur_pose_ = data; 
    }

    void do_tick() {
        // if there is a set_orientation request, turn turtle
        if (set_orientation_req_ != nullptr) {
            turn(set_orientation_req_->orientation);
        }

        // if there is a walk_distance request, walk turtle
        if (walk_distance_req_ != nullptr) {
            walk(walk_distance_req_->distance);
        }
    }

    bool set_orientation_cb(const std::shared_ptr<TodoServiceRequestTypeHere> req,
        std::shared_ptr<TodoServiceResponseTypeHere> resp) {
        // TODO: save the request to 'set_orientation_req_'

        // TODO: fill in 'resp' with true

        return true;
    }

    bool walk_distance_cb(const std::shared_ptr<TodoServiceRequestTypeHere> req,
        std::shared_ptr<TodoServiceResponseTypeHere> resp) {
        // TODO: verify if request valid (e.g. negative distance, projected x-y coordinates after walking the distance is outside boundary)

        // TODO: save the request to 'walk_distance_req_'

        // TODO: fill in 'resp' with true

        return true;
    }

    void turn(double orientation) {
        // TODO: calculate the angular distance between current angle and target angle
        // Hint: signed smallest distance between two angles:
        // see https://stackoverflow.com/questions/1878907/the-smallest-difference-between-2-angles
        //     ang_dist = fmod(req.orientation - cur_pos.theta + pi + 2 * pi, 2 * pi) - pi
        double ang_dist = ...;

        // TODO: check termination condition for turtle to stop turning

        // TODO: publish angular velocity
    }

    void walk(double /* distance */) {
        // TODO: find the error between current position and target position

        // TODO: check termination condition for turtle to stop walking

        // TODO: publish linear velocity
    }

private:
    rclcpp::TimerBase::SharedPtr timer_;
    turtlesim::msg::Pose cur_pose_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr sub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
    rclcpp::Service<turtle_path::srv::SetOrientation>::SharedPtr set_orientation_srv_;
    std::shared_ptr<turtle_path::srv::SetOrientation::Request> set_orientation_req_;
    // TODO: add a service server here for turtle's walking service...
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PathManagerNode>());
    rclcpp::shutdown();
    return 0;
}