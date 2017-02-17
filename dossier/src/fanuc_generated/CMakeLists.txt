cmake_minimum_required(VERSION 2.8.3)
project(fanuc_generated)

find_package(catkin REQUIRED roslaunch)
find_package(catkin REQUIRED COMPONENTS moveit_ros_planning_interface)
find_package(Boost REQUIRED COMPONENTS thread)

include_directories(include ${catkin_INCLUDE_DIRS})

catkin_package()

add_executable(plan_fanuc src/plan_fanuc.cpp)
target_link_libraries(plan_fanuc ${catkin_LIBRARIES} ${Boost_LIBRARIES})

roslaunch_add_file_check(launch)

install(DIRECTORY launch DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  PATTERN "setup_assistant.launch" EXCLUDE)
install(DIRECTORY config DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
