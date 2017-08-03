// problability_cal.cpp : Defines the entry point for the console application.
//

#include <iostream.h>
#include <time.h> 
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>

const double pi=3.141592653589;

	double random(signed int min,signed int max)
	{
		int interger=(rand() % (max-min))+ min;
		return interger+rand()/double(RAND_MAX);
	}

	double throwPin(unsigned int range,double ratio,int attempt)
	{
		int cross_time;
		double angle,x_pin[2];//,y_pin[2];
		srand((unsigned)time(NULL)); //初始化随机数生成器
		cross_time=0;
		for(int i=1;i<=attempt;i++)
		{
			angle=2*pi*(rand()/(double)RAND_MAX);
			x_pin[0]=random(~range+1,range);
				//y_pin[0]=random(-1000,1000);
			x_pin[1]=x_pin[0]+cos(angle);
				//y_pin[1]=y_pin[0]+sin(angle);
			if((int)(x_pin[0]/ratio)!=(int)(x_pin[1]/ratio)) cross_time++;
				//printf("%d\n",cross_time);
				//printf("%f\n",angle);
				//printf("(%f,%f)(%f,%f)\n",x_pin[0],y_pin[0],x_pin[1],y_pin[1]);
				//printf("%f,%f\n",x_pin[0],x_pin[1]);
		}
		return (double)cross_time/(double)attempt;
	}



int main(int argc, char* argv[])
{
	while(true){
	double distance;   int attempts;
	cout<<"请输入平行线与针距离比：";
	cin>>distance;
	cout<<"请输入实验次数(10^n)：";
	cin>>attempts;


	double p=throwPin(5000,distance,(int)pow(10,attempts));
	

	printf("概率为%f,公式计算为%f\n",p,2/(pi*distance));
	printf("计算pi的值为%f\n",2/(p*distance));
	getchar();
	}
	return 0;
}


