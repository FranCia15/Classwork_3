#include "ros/ros.h"
#include "PUB_SUB/my_msg.h"
#include <iostream>
#include "cmath"

using namespace std;

float P = 0; 
float A = 0;

int main(int argc, char **argv){

    P = atof(argv[1]);
    A = atof(argv[2]);

    // initialize the ros node: publisher
    ros::init(argc, argv, "sinu_publisher");

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<PUB_SUB::my_msg>("/my_msg",1);
    ros::Rate rate(10);

    PUB_SUB::my_msg msg;

    msg.Period = P ;
    msg.Amplitude = A;

    double t = 0.0;

    while (ros::ok()) {
        
        msg.CurrentValue = A*sin(2*M_PI*t/P);
        t+=0.1;

        // print
        ROS_INFO("Period: %f", msg.Period);
        ROS_INFO("Amplitude: %f", msg.Amplitude);
        ROS_INFO("Current Value: %f", msg.CurrentValue);

        // publish the message 
        pub.publish(msg);

        // rate to mantain the 10 HZ
        rate.sleep();

    }

    return 0; 
}




