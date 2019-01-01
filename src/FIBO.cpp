#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <sstream>

int main(int argc,char **argv)
{
ros::init(argc,argv,"Fibin");
ros::NodeHandle n;

ros::Publisher Fib_pub = n.advertise<std_msgs::Int32>("INPUT",1000);
ros::Rate loop_rate(10);

std_msgs::Int32 num;
num.data=0;
std::cout<<"Give Input";
std::cin>>num.data;
Fib_pub.publish(num);
std::cin>>num.data;
Fib_pub.publish(num);
std::cin>>num.data;
Fib_pub.publish(num);
std::cin>>num.data;
Fib_pub.publish(num);
return 0;
}
