#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Int32MultiArray.h>

class Fib
{	
	ros::Publisher Fib_pub1;
	ros::Publisher Fib_pub2;
	ros::Subscriber in;
	ros::NodeHandle n;

public: 	
	void callback(const std_msgs::Int32::ConstPtr& Num);
	
	void abc();
	
	void pub1()
	{	
		std_msgs::Int32 num;
		num.data=0;
		std::cout<<"Give Input";
		std::cin>>num.data;
		Fib_pub1.publish(num);
	}
	
	void pub2(std_msgs::Int32MultiArray fib)
	{	
		Fib_pub2.publish(fib);
       	}
};

	
void Fib::callback(const std_msgs::Int32::ConstPtr& Num)
{
	std_msgs::Int32 fib1,fib2;
        fib1.data=1;fib2.data=1;
	std_msgs::Int32MultiArray fib;
        for(int i=0;i<Num->data;i++)
        
	{
		std_msgs::Int32 temp;
       	        temp.data=fib2.data;
       	        fib2.data=fib1.data+fib2.data;
       	        fib1.data=temp.data;
       	        fib.data.push_back(fib1.data);
	}
	
      	 pub2(fib);
}

 void Fib::abc()
{
	Fib_pub1 = n.advertise<std_msgs::Int32>("INPUT",1000);
        Fib_pub2 = n.advertise<std_msgs::Int32MultiArray>("OUTPUT",1000);
        in= n.subscribe("INPUT",1000,&Fib::callback,this);
}


int main(int argc,char** argv)
{
	ros::init(argc,argv,"FIBO");
	Fib abcde;
	abcde.abc();	
	abcde.pub1();
	
	sleep(3);
	ros::spinOnce();
	return 0;
}
