#include<ros/ros.h>
#include<beginner_tutorials/CombinedInfo.h>

void  user(beginner_tutorials::CombinedInfo& msgs)
{
	int i,j,k;
	std::cout<<"Enter linear acceleration along axises:";
	for(i=0;i<3;i++){
		std::cin>>msgs.linear_acceleration[i];
	}
	std::cout<<"Enter angular velocity in all axises:";
	for(j=0;j<3;j++){
		std::cin>>msgs.angular_velocity[j];
	}
	std::cout<<"Enter the rotation along axises:";
	for(k=0;k<3;k++){
		std::cin>>msgs.rotation[k];
	}
}

int main(int argc , char** argv ){

ros::init(argc,argv,"publ");
ros::NodeHandle nh;
ros::Publisher pub =nh.advertise<beginner_tutorials::CombinedInfo>("ContinousCombinedInfo",1000);
beginner_tutorials::CombinedInfo msg;
while(ros::ok()){
	user(msg);
	pub.publish(msg);
	ros::spinOnce();
}
return 0;

}