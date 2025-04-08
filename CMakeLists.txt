cmake_minimum_required(VERSION 3.4.0)
project(tiago_gazebo)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

find_package(rclcpp REQUIRED)
find_package(trajectory_msgs REQUIRED)

add_executable(tiago_arm_trajectory_node scripts/tiago_arm_trajectory_node.cpp)
ament_target_dependencies(tiago_arm_trajectory_node rclcpp trajectory_msgs)

install(TARGETS
  tiago_arm_trajectory_node
  DESTINATION lib/${PROJECT_NAME})

install(
  PROGRAMS scripts/tuck_arm.py
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  find_package(launch_testing_ament_cmake REQUIRED)
  find_package(play_motion2_msgs REQUIRED)
  find_package(sensor_msgs REQUIRED)

  # tuck_arm_test
  ament_add_gtest_executable(tuck_arm_test
    test/tuck_arm_test.cpp
  )
  ament_target_dependencies(tuck_arm_test
    launch_testing_ament_cmake
    play_motion2_msgs
    rclcpp
    sensor_msgs
  )

  install(
    TARGETS tuck_arm_test
    DESTINATION share/${PROJECT_NAME}/test
  )

  add_launch_test(
    test/tuck_arm_test.launch.py
  )
endif()

ament_auto_package(INSTALL_TO_SHARE config launch)
