cmake_minimum_required(VERSION 3.8)
project(turtle_ps4)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_srvs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)
find_package(m2_interfaces REQUIRED)

add_executable(ps4_controller src/ps4_controller.cpp)
ament_target_dependencies(ps4_controller
  rclcpp
  std_srvs
  geometry_msgs
  turtlesim
  m2_interfaces
)

install(
  TARGETS ps4_controller
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})

ament_package()
