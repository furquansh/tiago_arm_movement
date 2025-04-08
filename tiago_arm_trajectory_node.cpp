#include <rclcpp/rclcpp.hpp>
#include <trajectory_msgs/msg/joint_trajectory.hpp>
#include <trajectory_msgs/msg/joint_trajectory_point.hpp>
#include <iostream>
#include <vector>
#include <sstream>

class TiagoArmTrajectoryNode : public rclcpp::Node {
public:
    TiagoArmTrajectoryNode() : Node("tiago_arm_trajectory_node") {
        pub_ = this->create_publisher<trajectory_msgs::msg::JointTrajectory>(
            "/arm_controller/joint_trajectory", 10);
        run();
    }

private:
    rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr pub_;

    void run() {
        std::string input;
        while (rclcpp::ok()) {
            std::cout << "\nEnter 7 joint positions (radians) or 'exit': ";
            std::getline(std::cin, input);

            if (input == "exit") break;

            std::stringstream ss(input);
            std::vector<double> positions;
            double val;
            while (ss >> val) positions.push_back(val);

            if (positions.size() != 7) {
                std::cout << "Please enter exactly 7 values.\n";
                continue;
            }

            trajectory_msgs::msg::JointTrajectory msg;
            msg.joint_names = {
                "arm_1_joint", "arm_2_joint", "arm_3_joint", "arm_4_joint",
                "arm_5_joint", "arm_6_joint", "arm_7_joint"};

            trajectory_msgs::msg::JointTrajectoryPoint point;
            point.positions = positions;
            point.time_from_start = rclcpp::Duration::from_seconds(3.0);
            msg.points.push_back(point);

            pub_->publish(msg);
        }

        rclcpp::shutdown();
    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    std::make_shared<TiagoArmTrajectoryNode>();
    rclcpp::spin_some(rclcpp::Node::make_shared("tiago_arm_trajectory_node"));
    return 0;
}
