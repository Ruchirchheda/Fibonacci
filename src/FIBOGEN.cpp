#include <ros/ros.h>
#include <std_msgs/Int32MultiArray.h>
#include <std_msgs/Int32.h>

void gen1(const std_msgs::Int32::ConstPtr& Num)
{ros::NodeHandle n;
	std_msgs::Int32 fib1,fib2;
	fib1.data=1;fib2.data=1;
	std_msgs::Int32MultiArray fib;
	for(int i=0;i<Num->data;i++)
	{std_msgs::Int32 temp;
		temp.data=fib2.data;
		fib2.data=fib1.data+fib2.data;
		fib1.data=temp.data;
		fib.data.push_back(fib1.data);}

	ros::Publisher out=n.advertise<std_msgs::Int32MultiArray>("FibNumbers",1000);
	ros::Rate loop_rate(10);
	while(ros::ok()){
		loop_rate.sleep();
		out.publish(fib);
		ros::spinOnce();}

}


int main(int argc, char **argv)
{using namespace std::placeholders;
	ros::init(argc, argv,"FibonacciGenerator");
	ros::NodeHandle n;
	ros::Subscriber in= n.subscribe("INPUT",1000,gen1);
	ros::spin();
	return 0;
}
