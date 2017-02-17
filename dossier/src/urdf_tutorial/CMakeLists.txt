cmake_minimum_required(VERSION 2.8.3)

project(urdf_tutorial)

find_package(catkin REQUIRED roslaunch)
find_package(catkin REQUIRED COMPONENTS moveit_ros_planning_interface)
find_package(Boost REQUIRED COMPONENTS thread)

include_directories(include ${catkin_INCLUDE_DIRS})

catkin_package()

#include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)
#rosbuild_add_executable(add_cylinder src/addCylinder.cpp)

###### LALALALA
#add_executable(foret_de_cylindres src/foret_de_cylindres.cpp)
#target_link_libraries(foret_de_cylindres ${catkin_LIBRARIES} ${Boost_LIBRARIES})
###### FIN LALA

#install(TARGETS foret_de_cylindres DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

roslaunch_add_file_check(launch)








#install(DIRECTORY config images launch rviz urdf
#  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

