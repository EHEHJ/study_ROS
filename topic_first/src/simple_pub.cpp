#include "ros/ros.h"
#include "topic_first/simplemsg.h" // beginner:package name msgname
#include <sstream>

int main(int argc, char **argv){
    ros::init(argc,argv, "talker");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<topic_first::simplemsg>("chatter",1000); 
    ros::Rate loop_rate(10);
    int count=0;
    while(ros::ok()){
        topic_first::simplemsg msg;

        //gen msg
        std::stringstream ss;
        ss << "hello world "<< count;
        msg.data = ss.str();

        //load id from param
        std::string id;
        n.param("/chatter_id", id, std::string("no id registered"));
        msg.id =id;

        ROS_INFO("[%s] : %s ", msg.id.c_str(), msg.data.c_str());
        chatter_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }
    return 0;
}