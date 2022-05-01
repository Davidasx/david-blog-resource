#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;
double PI=3.1415926535897932;
int main(){
	int R,G,B,SECONDS;
	cin>>R>>G>>B>>SECONDS;
	initgraph(200,200);
	setfillcolor(R*256*256+G*256+B);
	solidrectangle(0,0,200,200);
	setfillcolor(0);
	solidcircle(100,100,60);
	setfillcolor(255*256*256+255*256+255);
	solidcircle(100,100,50);
	for(int i=30-SECONDS;i<=30;i++){
		double A=cos(i*1.00*PI/30.00);
		double B=sin(i*1.00*PI/30.00);
		setlinecolor(BLUE);
		line(100,100,109,105);
		setlinecolor(YELLOW);
		line(100,100,100,80);
		setlinecolor(RED);
		line(100,100,100-B*30,100+A*30);
		Sleep(1000);
		setlinecolor(WHITE);
		line(100,100,100-B*30,200+A*30);
		if(GetAsyncKeyState('A')){
			closegraph();
			return 0;
		}
	}
	closegraph();
	return 0;
}


