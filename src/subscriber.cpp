#include "ros/ros.h"
#include <iostream>
#include "cmath"
#include "PUB_SUB/my_msg.h"
#include "std_msgs/Float32.h"
#include "boost/thread.hpp"

using namespace std;

class sinu_subscriber {
    	public:
        sinu_subscriber();
        void topic_cb(PUB_SUB::my_msg::ConstPtr msg );
        void filter();
        void filter_thread();

    private: 
        float val; 
        float nf_val; 
        float a;
        ros::NodeHandle _nh;
        ros::Subscriber _sub;
        ros::Publisher _pub;
        ros::Rate _rate;
            
};

sinu_subscriber::sinu_subscriber():_rate(10){
    val=0; 
    nf_val=0; 
    a=0.1;
     _sub= _nh.subscribe("/my_msg",1, &sinu_subscriber::topic_cb,this);
    _pub= _nh.advertise<std_msgs::Float32>("/low_pass_filtered_signal",1);
}
void sinu_subscriber::topic_cb(PUB_SUB::my_msg::ConstPtr msg ){
    	// print
        ROS_INFO("Listener, Period: %f, Amplitude: %f, Current Value: %f",msg->Period, msg->Amplitude, msg->CurrentValue);
        nf_val= msg -> CurrentValue;

}
void sinu_subscriber::filter(){
    
    std_msgs::Float32 FValue;
    while(ros::ok()){
        val=(1-a)*val+a*nf_val;
        ROS_INFO("Filtered Value: %f", val);
        FValue.data=val;
        _pub.publish(FValue);
        _rate.sleep();
    }
}
void sinu_subscriber::filter_thread(){
    boost::thread(&sinu_subscriber::filter, this);
}
int main (int argc, char** argv ){
    ros::init(argc,argv,"sinu_subscriber");
    sinu_subscriber _SUB;
    _SUB.filter_thread();
    ros::spin();
    return 0;
}
