#include <ros.h>

#include <ros/time.h>

#include <visualization_msgs/Marker.h>
ros::NodeHandle  nh;

visualization_msgs::Marker marker;
ros::Publisher mark("mark", &marker);


char base_link[] = "/base_link";
char odom[] = "/odom";

int marker_id=1;
void setup() {
  nh.initNode();
  nh.advertise(mark);

}

void loop() {
 
visualization_msgs::Marker marker;
 marker.header.frame_id =base_link;
 marker.header.stamp = ros::Time();
 marker.ns = "my_namespace";
 marker.id = marker_id;
 marker.type = visualization_msgs::Marker::SPHERE; //if the mine above the ground will be shown as a sphere 
 marker.action = visualization_msgs::Marker::ADD;
 marker.pose.position.x = 1;
 marker.pose.position.y = 1;
 marker.pose.position.z = 1;
 marker.pose.orientation.x = 0.0;
 marker.pose.orientation.y = 0.0;
 marker.pose.orientation.z = 0.0;
 marker.pose.orientation.w = 1.0;
 marker.scale.x = 1;
 marker.scale.y = 0.1;
 marker.scale.z = 0.1;
 marker.color.a = 1.0; // Don't forget to set the alpha!
 marker.color.r = 0.0;
 marker.color.g = 1.0;
 marker.color.b = 0.0;
//only if using a MESH_RESOURCE marker type:
// marker.mesh_resource = "package://pr2_description/meshes/base_v0/base.dae";
 mark.publish( &marker );
  nh.spinOnce();
 
  delay(10);
  marker_id++;

}
