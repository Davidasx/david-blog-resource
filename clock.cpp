#include <graphics.h>
#include <conio.h>
double PI=3.1415926535897932;
int main(){
	initgraph(400,400);
	circle(200,200,100);
	int SECONDS=30;
	for(int i=30-SECONDS;i<=30;i++){
		double A=cos(i*1.00*PI/30.00);
		double B=sin(i*1.00*PI/30.00);
		setlinecolor(BLUE);
		line(200,200,217,210);
		setlinecolor(YELLOW);
		line(200,200,200,160);
		setlinecolor(RED);
		line(200,200,200-B*60,200+A*60);
		Sleep(1000);
		setlinecolor(BLACK);
		line(200,200,200-B*60,200+A*60);
	}
	_getch();
	closegraph();
	return 0;
}


