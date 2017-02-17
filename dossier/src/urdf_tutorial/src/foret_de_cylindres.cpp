// Ceci est une forêt de cylindres

#include <ros/ros.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>



int main(int argc, char **argv)
{
  ros::init(argc, argv, "foret_de_cylindres");
  ros::NodeHandle node_handle;  
  ros::AsyncSpinner spinner(1);
  spinner.start();
  ros::Publisher object_to_display;

  object_to_display= node_handle.advertise<moveit_msgs::CollisionObject>("collision_object",10);

  /* This sleep is ONLY to allow Rviz to come up */
  sleep(5.0);

// We will use the :planning_scene_interface:`PlanningSceneInterface`
  // class to deal directly with the world.
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface; 


// First, we will define the collision object message.
  moveit_msgs::CollisionObject collision_object;
  //collision_object.header.frame_id = group.getPlanningFrame();

  /* The id of the object is used to identify it. */
  collision_object.id = "cylinder1";

  /* Define a cylinder to add to the world. */
  shape_msgs::SolidPrimitive primitive;
  primitive.type = primitive.CYLINDER;
  primitive.dimensions.resize(2);
  primitive.dimensions[0] = 2;
  primitive.dimensions[1] = 2;

   /* A pose for the cylinder (specified relative to frame_id) */
  geometry_msgs::Pose cylinder_pose;
  cylinder_pose.orientation.w = 1.0;
  cylinder_pose.position.x =  0.6;
  cylinder_pose.position.y = -0.4;
  cylinder_pose.position.z =  1.2;



  collision_object.primitives.push_back(primitive);
  collision_object.primitive_poses.push_back(cylinder_pose);
  collision_object.operation = collision_object.ADD;

  // Creation of a vector/list of collision_objectS 
  std::vector<moveit_msgs::CollisionObject> list_collision_objects;  
  list_collision_objects.push_back(collision_object);  


  // Now, let's add the collision object into the world
  ROS_INFO("Add an object into the world");  
  planning_scene_interface.addCollisionObjects(list_collision_objects);
  object_to_display.publish(collision_object);

  /* Sleep so we have time to see the object in RViz */
  sleep(5.0);

  // Now, let's remove the collision object from the world.
  /*ROS_INFO("Remove the object from the world");  
  std::vector<std::string> object_ids;
  object_ids.push_back(collision_object.id);  
  planning_scene_interface.removeCollisionObjects(object_ids);
  // Sleep to give Rviz time to show the object is no longer there. 
  sleep(4.0);*/

}