#include <ros/ros.h>

#include </home/fgallego/dossier/src/urdf_tutorial/include/CollisionObject.h>
#include </home/fgallego/dossier/src/urdf_tutorial/include/Shape.h>

int main(int argc, char** argv) {

  ros::init(argc, argv, "addCylinder");

  ros::NodeHandle nh;

  ros::Publisher object_in_map_pub_;
  object_in_map_pub_  = nh.advertise<CollisionObject>("collision_object", 10);

  ros::Duration(2.0).sleep();// This delay is so critical, otherwise the first published object may not be added in the collision_space by the environment_server

  //add the cylinder into the collision space
  CollisionObject cylinder_object;
  cylinder_object.id = "pole";
  cylinder_object.operation.operation = CollisionObjectOperation::ADD;
  cylinder_object.header.frame_id = "base_link";
  cylinder_object.header.stamp = ros::Time::now();
  Shape object;
  object.type = Shape::CYLINDER;
  object.dimensions.resize(2);
  object.dimensions[0] = .1;
  object.dimensions[1] = .75;
  geometry_msgs::Pose pose;
  pose.position.x = .6;
  pose.position.y = -.6;
  pose.position.z = .375;
  pose.orientation.x = 0;
  pose.orientation.y = 0;
  pose.orientation.z = 0;
  pose.orientation.w = 1;
  cylinder_object.shapes.push_back(object);
  cylinder_object.poses.push_back(pose);

  cylinder_object.id = "pole";
  object_in_map_pub_.publish(cylinder_object);

  ROS_INFO("Should have published");

  ros::Duration(2.0).sleep();

  ros::shutdown();
}
