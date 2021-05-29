#include "ros/ros.h"
#include "std_msgs/String.h"

void call_sub(const std_msgs::String::ConstPtr& msg){
	ROS_INFO("Recivied!");

}

int main(int argc,char **argv){
	int count = 0;

	ros::init(argc,argv,"test_pub_sub");
	ros::NodeHandle n;

	//PUB_NAME = NODE.advertise<MSG_TYPE>("TOPIC NAME",buff);
	ros::Publisher pub = n.advertise<std_msgs::String>("pub_test",1000);
	
	//SUB_NAME = NODE.subscribe("TOPIC_NAME",Buff,Call function);
	ros::Subscriber sub = n.subscribe("pub_test",1000,call_sub);
	

	ros::Rate freq(1);
	while(ros::ok()){
		std_msgs::String msg;
		
		msg.data = count++;

		pub.publish(msg);
			
		ros::spinOnce();

		freq.sleep();

	}

return 0;
}


