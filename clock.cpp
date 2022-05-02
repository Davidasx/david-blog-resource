#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;
double PI=3.1415926535897932;
double coef=0.95;
int main(){
	int R,G,B,SECONDS;
	cin>>R>>G>>B>>SECONDS;
	initgraph(200,200);
	setfillcolor(RGB(R,G,B));
	solidrectangle(0,0,200,200);
	setfillcolor(RGB(255,255,255));
	solidcircle(100,100,50);
	for(int i=30-SECONDS;i<=30;i++){
		double A=cos(i*1.00*PI/30.00);
		double B=sin(i*1.00*PI/30.00);
		setfillcolor(RGB(255,255,255));
		solidcircle(100,100,50);
		for(int j=0;j<12;j++){
			double u=50.00*cos(j*1.00*PI/6.00);
			double v=50.00*sin(j*1.00*PI/6.00);
			setlinecolor(BLACK);
			line(100-u*0.95,100+v*0.95,100-u,100+v);
		}
		setlinecolor(BLUE);
		line(100,100,126,115);
		setlinecolor(GREEN);
		line(100,100,100,60);
		setlinecolor(RED);
		line(100,100,100-B*45,100+A*45);
		Sleep(1000);
		if(GetAsyncKeyState('A')){
			closegraph();
			return 0;
		}
	}
	Sleep(5000);
	closegraph();
	return 0;
}


