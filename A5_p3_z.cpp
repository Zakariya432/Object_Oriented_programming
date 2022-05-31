//Name=Zakariya Momin Mondal
//CSE-38/20

#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;


class DM{
	public:
		float m,cm;
	void input();

	};

class DB{
	public:
		float f,in;
	void input();
	friend void sum(DM,DB);
};

void sum(DM x,DB y){
	float num1,num2;
	cout<<"Enter the distance in meters & centimeters:"<<"\n";
	cin>>x.m>>x.cm;
	cout<<"Enter the distance in feet & inches:"<<"\n";
	cin>>y.f>>y.in;
	
	num1=x.m+(y.f)/3.281;
	num2=x.cm+(y.in)*2.54;

	cout<<"Meter + Feet="<<num1<<"ms"<<"\n";
	cout<<"Centimeters + inches+"<<num2<<"cms"<<"\n";

}

int main(){
	DM x;
	DB y;
	sum(x,y);

}