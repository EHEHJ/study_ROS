#include "ros/ros.h"
#include "service_tutorials/SrvTutorials.h"

bool calculation(service_tutorials::SrvTutorials::Request &req, service_tutorials::SrvTutorials::Response &res){
    res.result = req.a + req.b;

    ROS_INFO("requeset : x=%ld, y=%ld", static_cast<long int>(req.a), static_cast<long int>(req.b));
    ROS_INFO("sending back response : %ld", static_cast<long int>(res.result));
    
    return true;
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "ServiceServer");
    ros::NodeHandle nh;

    ros::ServiceServer service_server = nh.advertiseService("service_tutorial", calculation);

    ROS_INFO("ready srv server!");
    ros::spin();
}