#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>
#include <turtlesim/Pose.h>
#include <iostream>
#define EPSINON  0.00000001
#define DVALUE 1.5
using namespace std;

bool Aupdate = true;
bool Bupdate = true;
bool Cupdate = true;
bool Dupdate = true;
bool Eupdate = true;

bool leaderupdate = false;

double leaderx = 0;
double leadery = 0;
int Acount = 0;
int Bcount = 0;
int Ccount = 0;
int Dcount = 0;
int Ecount = 0;

void myprint(void)
{
    cout << "---------------------------"<<endl;
    cout << "ALLcount = " << Acount+ Bcount+ Ccount+ Dcount+ Ecount <<endl;
    cout << "Acount   = " << Acount <<endl;
    cout << "Bcount   = " << Bcount <<endl;
    cout << "Ccount   = " << Ccount <<endl;
    cout << "Dcount   = " << Dcount <<endl;
    cout << "Ecount   = " << Ecount <<endl;
    cout << "---------------------------"<<endl;

}


void AposeCallback(const turtlesim::PoseConstPtr& msg)
{
    double distance = sqrt(pow(msg->x - leaderx, 2) + pow(msg->y - leadery, 2)); 
    
    if(distance < DVALUE && Aupdate)
    {
        Acount = Acount +1;
        myprint();
        Aupdate = false;
    }

}

void BposeCallback(const turtlesim::PoseConstPtr& msg)
{
    double distance = sqrt(pow(msg->x - leaderx, 2) + pow(msg->y - leadery, 2)); 
    
    if(distance < DVALUE && Bupdate)
    {
        Bcount = Bcount +1;
        myprint();
        Bupdate = false;
    }

}

void CposeCallback(const turtlesim::PoseConstPtr& msg)
{
    double distance = sqrt(pow(msg->x - leaderx, 2) + pow(msg->y - leadery, 2)); 
    
    if(distance < DVALUE && Cupdate)
    {
        Ccount = Ccount +1;
        myprint();
        Cupdate = false;
    }

}

void DposeCallback(const turtlesim::PoseConstPtr& msg)
{
    double distance = sqrt(pow(msg->x - leaderx, 2) + pow(msg->y - leadery, 2)); 
    
    if(distance < DVALUE && Dupdate)
    {
        Dcount = Dcount +1;
        myprint();
        Dupdate = false;
    }

}
void EposeCallback(const turtlesim::PoseConstPtr& msg)
{
    double distance = sqrt(pow(msg->x - leaderx, 2) + pow(msg->y - leadery, 2)); 
    
    if(distance < DVALUE && Eupdate)
    {
        Ecount = Ecount +1;
        myprint();
        Eupdate = false;
    }

}

void leaderposeCallback(const turtlesim::PoseConstPtr& msg)
{
    

    if(fabs(msg->x - leaderx)>EPSINON && fabs(msg->y - leadery)>EPSINON)
    {
        leaderx = msg->x;
        leadery = msg->y;
        Aupdate = true;
        Bupdate = true;
        Cupdate = true;
        Dupdate = true;
        Eupdate = true;
      
        
    } 

}
 
int main(int argc, char** argv)
{
    // 初始化节点
    ros::init(argc, argv, "my_turtle_count");
 
    ros::NodeHandle node;
 

    ros::Subscriber Asub = node.subscribe("A/pose", 10, &AposeCallback);
    ros::Subscriber Bsub = node.subscribe("B/pose", 10, &BposeCallback);
    ros::Subscriber Csub = node.subscribe("C/pose", 10, &CposeCallback);
    ros::Subscriber Dsub = node.subscribe("D/pose", 10, &DposeCallback);
    ros::Subscriber Esub = node.subscribe("E/pose", 10, &EposeCallback);
    ros::Subscriber leadersub = node.subscribe("turtle_leader/pose", 10, &leaderposeCallback);

 
    ros::spin();
    
    return 0;
};
