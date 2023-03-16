// #include <ros/ros.h>
// #include <cartographer_ros_msgs/StartTrajectory.h>
// #include <cartographer_ros_msgs/FinishTrajectory.h>


// int main(int argc, char **argv)
// {
//   ros::init(argc, argv, "start_trajectory_client");
//   ros::NodeHandle n;

//   // Create a service client for the start_trajectory service
//   ros::ServiceClient Startclient = 
//     n.serviceClient<cartographer_ros_msgs::StartTrajectory>("/start_trajectory");
//   ros::ServiceClient finishclient = 
//     n.serviceClient<cartographer_ros_msgs::StartTrajectory>("/finish_trajectory");


//   // Create a StartTrajectoryRequest object and fill it with the necessary parameters
//   cartographer_ros_msgs::StartTrajectory::Request startreq;
//   cartographer_ros_msgs::FinishTrajectory::Request finishreq;
//   finishreq.trajectory_id = 1 ; // int
//   Startclient.call(finishreq, res);

//   startreq.configuration_basename = "my_map.lua"; // string
//   startreq.configuration_directory=""; // string
//   startreq.use_initial_pose = true; // bool
//   startreq.initial_pose = geometry_msgs; // geometry _msgs
//   startreq.relative_to_trajectory_id= ; /// int 
//   startreq.trajectory_id = // int
//   // Call the start_trajectory service
//   cartographer_ros_msgs::StartTrajectory::Response res;
//   Startclient.call(startreq, res)

//   return 0;
// }



#include <ros/ros.h>
#include <cartographer_ros_msgs/StartTrajectory.h>
#include <cartographer_ros_msgs/FinishTrajectory.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>


// Initialize ROS node
ros::init(argc, argv, "initial_pose_subscriber");

// Create ROS node handle
ros::NodeHandle nh;


void initialPoseCallback_0(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{

    // Create a service client for the start_trajectory service
    ros::ServiceClient Startclient = nh.serviceClient<cartographer_ros_msgs::StartTrajectory>("/start_trajectory");
    ros::ServiceClient finishclient = nh.serviceClient<cartographer_ros_msgs::StartTrajectory>("/finish_trajectory");


    // Create a StartTrajectoryRequest object and fill it with the necessary parameters
    cartographer_ros_msgs::StartTrajectory::Request startreq;
    cartographer_ros_msgs::FinishTrajectory::Request finishreq;
    finishreq.trajectory_id = 0 ; // int
    if (finishclient.call(finishreq, res))
    {
        ROS_INFO("Finished");
    }

    startreq.configuration_basename = "rplidar.lua"; // string
    startreq.configuration_directory=" "; // string
    startreq.use_initial_pose = true; // bool
    startreq.initial_pose = msg->pose; // geometry _msgs
    startreq.relative_to_trajectory_id = 0; /// int 
    startreq.trajectory_id = 0;// int
    // Call the start_trajectory service
    cartographer_ros_msgs::StartTrajectory::Response res;

    if(Startclient.call(startreq, res))
    
    {
        ROS_INFO("SUCCESS");
    }

  return 0;

}
void initialPoseCallback_1(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
    // Initial pose received, do something with it
    ROS_INFO("Initial set num: %d\n", 1);
    // ROS_INFO("Initial position received: x=%f\n",msg->pose.pose.position.x);
    // ROS_INFO("Initial position received: y=%f\n",msg->pose.pose.position.y);
    // ROS_INFO("Initial position received: z=%f\n",msg->pose.pose.position.z);
    // ROS_INFO("Initial orientation received: x=%f\n",msg->pose.pose.orientation.x);
    // ROS_INFO("Initial orientation received: y=%f\n",msg->pose.pose.orientation.y);
    // ROS_INFO("Initial orientation received: z=%f\n",msg->pose.pose.orientation.z);
    // ROS_INFO("Initial orientation received: w=%f\n",msg->pose.pose.orientation.w);
}
void initialPoseCallback_2(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
    // Initial pose received, do something with it
    ROS_INFO("Initial set num: %d\n", 2);
    // ROS_INFO("Initial position received: x=%f\n",msg->pose.pose.position.x);
    // ROS_INFO("Initial position received: y=%f\n",msg->pose.pose.position.y);
    // ROS_INFO("Initial position received: z=%f\n",msg->pose.pose.position.z);
    // ROS_INFO("Initial orientation received: x=%f\n",msg->pose.pose.orientation.x);
    // ROS_INFO("Initial orientation received: y=%f\n",msg->pose.pose.orientation.y);
    // ROS_INFO("Initial orientation received: z=%f\n",msg->pose.pose.orientation.z);
    // ROS_INFO("Initial orientation received: w=%f\n",msg->pose.pose.orientation.w);
}

int main(int argc, char** argv)
{

    // Create subscriber to initial pose topic
    ros::Subscriber initialPoseSub_0 = nh.subscribe<geometry_msgs::PoseWithCovarianceStamped>("/initialpose_0", 1, initialPoseCallback_0);
    ros::Subscriber initialPoseSub_1 = nh.subscribe<geometry_msgs::PoseWithCovarianceStamped>("/initialpose_1", 1, initialPoseCallback_1);
    ros::Subscriber initialPoseSub_2 = nh.subscribe<geometry_msgs::PoseWithCovarianceStamped>("/initialpose_2", 1, initialPoseCallback_2);


    // Spin and process callbacks
    ros::spin();

    return 0;
}