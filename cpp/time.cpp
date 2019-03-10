#include<iostream>
using namespace std;
class time1
{
int sec,min,hour;
//static int sec,min,hour;
public:
//static void initialize(void)
void initialize(void)
{
cout<<"enter the time: ";
cin>>hour;
cin>>min;
cin>>sec;
}
//static void display(void)
void display(void)const
{
cout<<"time: "<<hour<<":"<<min<<":"<<sec<<endl;
}
//static void time_sec(void)
void time_sec(void)const
{
int time;
time=sec+(min*60)+(hour*3600);
cout<<"total sec: "<<time<<" sec"<<endl;
}
//static void time_min(void)
void time_min(void)const
{
float time;
time=min+((float)sec/60)+(hour*60);
cout<<"total min: "<<time<<" min"<<endl;
}
//static void time_hour(void)
void time_hour(void)const
{
float time;
//hour++;
time=hour+((float)(sec/3600))+((float)(min/60));
cout<<"total hour: "<<time<<" hours"<<endl;
}
};
/*
int time1::sec,min,hour;
time1::initialize();
time1::display();
time1::time_sec();
time1::time_min();
time1::time_hour();
*/
main()
{
time1 tm;
tm.initialize();
tm.display();
tm.time_sec();
tm.time_min();
tm.time_hour();
}
