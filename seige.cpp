#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
bool lst;
int rg,pp,ee,blood,p1,p2,cx,cy,ex,ey,harm[25][25],mrah[25][25];
struct object{
	int dx,dy,attack,health,explode,exrange;
	char show;
	object(){
		show='.';
		dx=dy=attack=explode=exrange=0;
		health=1000000000;
	}
};
int back=FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN;
int red=FOREGROUND_INTENSITY|FOREGROUND_RED;
int green=FOREGROUND_INTENSITY|FOREGROUND_GREEN;
int blue=FOREGROUND_INTENSITY|FOREGROUND_BLUE;
int yellow=FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED;
int purple=FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE;
void scta(int clr){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),clr);
}
vector<object> grid[25][25],dirg[25][25];
object T;
string sver="1.1.0";
string stim="20220416";
#define HACKED
#ifdef HACKED
string hver="1.0.0";
string htim="20220410";
int HEALTH=300;
int TOT=7;
string name[120]={"BLOOD","AUTO","LOCK","PASS","FREEZE","SUPER","FIRE"};
bool val[120];
#define BLOOD val[0]
#define AUTO val[1]
#define LOCK val[2]
#define PASS val[3]
#define FREEZE val[4]
#define SUPER val[5]
#define FIRE val[6]
int DOWN=9,RIGHT=9;
int DN,RG,shoot;
void autoplay(){
	if(shoot&&!lst){
		if(SUPER) T.attack=50;
		T.dx=-1;T.dy=0;
		if(cx!=1)
			grid[cx-1][cy].push_back(T);
		T.dx=0;T.dy=-1;
		if(cy!=1)
			grid[cx][cy-1].push_back(T);
		T.dx=0;T.dy=+1;
		if(cy!=21)
		grid[cx][cy+1].push_back(T);
		T.dx=+1;T.dy=0;
		if(cx!=21)
		grid[cx+1][cy].push_back(T);
		if(!FIRE) lst=true;
		shoot--;
		if(SUPER) T.attack=20;
	}
	else if(RG!=RIGHT&&!shoot)
		grid[cx][cy][pp].dy=+1,cy++,lst=false,RG++;
	else if(DN!=DOWN&&!shoot)
		grid[cx][cy][pp].dx=+1,cx++,lst=false,DN++;
	else lst=false;
	if(RG==RIGHT&&!PASS){
		shoot=0;
		for(int i=0;i<(int)(grid[6][2+RIGHT].size());i++)
			if(grid[6][2+RIGHT][i].show=='#')
				shoot=1;
	}
	if(DN==DOWN&&!shoot) shoot=1000000000;
}
#endif
int main(){
	#ifdef HACKED
	int cur=0;
	int MX=0;
	for(int i=0;i<7;i++) MX=max(MX,(int)(name[i].size()));
	system("cls");
	cout<<"SEIGE HACKER v"<<hver<<" ("<<htim<<") by David X"<<endl;
	cout<<"Press any key to start hacking."<<endl;
	getch();
	while(1){
		system("cls");
		cout<<"Choose which hacked features to use:"<<endl;
		cout<<"Use arrows to move,SPACE to select/deselect and ENTER to exit."<<endl;
		for(int i=0;i<TOT;i++){
			cout<<" ";
			if(i==cur) cout<<">";
			else cout<<" ";
			cout<<" [";
			for(int j=0;j<(MX-(int)(name[i].size()))/2;j++) cout<<" ";
			cout<<name[i];
			for(int j=0;j<(MX-(int)(name[i].size())+1)/2;j++) cout<<" ";
			cout<<"]: ";
			if(val[i]) cout<<"+";
			cout<<endl;
		}
		int p=getch();
		if(p==224){
			p=getch();
			if(p==72) cur=(cur+TOT-1)%TOT;
			if(p==80) cur=(cur+1)%TOT;
		}
		else if(p==32) val[cur]^=1;
		else if(p==10||p==13) break;
	}
	system("cls");
	cout<<"Selected features:";
	for(int i=0;i<7;i++) if(val[i]) cout<<name[i]<<" ";
	cout<<endl;
	cout<<"Press any key to start SEIGE."<<endl;
	getch();
	#endif
	system("cls");
	cout<<"SEIGE v"<<sver<<" ("<<stim<<") by David X"<<endl;
	#ifdef HACKER
	cout<<"Hacked with HACKER v"<<hver<<" ("<<htim<<")"<<endl;
	#endif
	cout<<"Press any key to start."<<endl;
	getch();
	srand(unsigned(time(NULL)));
	for(int i=6;i<=16;i++) for(int j=6;j<=16;j++){
		if(i==6||i==16||j==6||j==16){
			T.dx=T.dy=0;
			T.attack=1000000;T.health=1000;
			T.explode=10;T.exrange=1;
			#ifdef HACKED
			if(PASS) T.attack=0;
			#endif
			T.show='#';
			grid[i][j].push_back(T);
		} 
	}
	T.dx=T.dy=0;
	T.attack=20;T.health=500;
	T.explode=T.exrange=0;
	T.show='O';
	grid[11][11].push_back(T);
	T.dx=T.dy=0;
	T.attack=20;T.health=1000000;
	T.explode=T.exrange=0;
	T.show='+';
	for(int i=1;i<=21;i++) if(i<6||i>16)
		grid[i][i].push_back(T);
	for(int i=1;i<=21;i++) if(i<6||i>16)
		grid[i][22-i].push_back(T);
	T.dx=T.dy=0;
	T.attack=10;T.health=300;
	T.explode=T.exrange=0;
	T.show='@';
	#ifdef HACKED
	if(BLOOD) T.health=500,HEALTH=500;
	#endif
	grid[1][2].push_back(T);
	cx=1,cy=2,ex=11,ey=11;
	T.dx=T.dy=0;
	T.attack=20;T.health=10;
	T.explode=T.exrange=0;
	T.show='X';
	int rd=0;
	lst=false;
	while(1){
		rd++;
		system("cls");
		for(int i=0;i<(int)(grid[cx][cy].size());i++)
			if(grid[cx][cy][i].show=='@')
				grid[cx][cy][i].dx=grid[cx][cy][i].dy=0,pp=i;
		for(int i=0;i<(int)(grid[ex][ey].size());i++)
			if(grid[ex][ey][i].show=='O')
				grid[ex][ey][i].dx=grid[ex][ey][i].dy=0,ee=i;
		#ifdef HACKED
		if(LOCK) grid[cx][cy][pp].health=HEALTH;
		#endif
		blood=grid[cx][cy][pp].health;
		for(int i=1;i<=(blood-1)/10;i++) cout<<"=";
		cout<<">"<<blood<<endl;
		blood=grid[ex][ey][ee].health;
		for(int i=1;i<=(blood-1)/10;i++) cout<<"=";
		cout<<">"<<blood<<endl;
		for(int i=1;i<=21;i++){
			for(int j=1;j<=21;j++){
				if(grid[i][j].size()){
					if(grid[i][j][0].show=='#') scta(yellow);
					if(grid[i][j][0].show=='+') scta(blue);
					if(grid[i][j][0].show=='*'||grid[i][j][0].show=='X')
						scta(red);
					if(grid[i][j][0].show=='O') scta(green);
					if(grid[i][j][0].show=='@') scta(purple);
					cout<<grid[i][j][0].show;
					scta(back);
				}
				else cout<<".";
			}
			cout<<endl;
		}
		Sleep(100);
		if(rd%3==1){
			T.show='*';
			T.dx=-1;T.dy=-1;grid[ex-1][ey-1].push_back(T);
			T.dx=-1;T.dy=0;grid[ex-1][ey].push_back(T);
			T.dx=-1;T.dy=+1;grid[ex-1][ey+1].push_back(T);
			T.dx=0;T.dy=-1;grid[ex][ey-1].push_back(T);
			T.dx=0;T.dy=+1;grid[ex][ey+1].push_back(T);
			T.dx=+1;T.dy=-1;grid[ex+1][ey-1].push_back(T);
			T.dx=+1;T.dy=0;grid[ex+1][ey].push_back(T);
			T.dx=+1;T.dy=+1;grid[ex+1][ey+1].push_back(T);
			T.show='X';
		}
		#ifdef HACKED
		if(AUTO) autoplay();
		else{
		#endif
			if(GetAsyncKeyState(' ')&&!lst){
				#ifdef HACKED
				if(SUPER) T.attack=50;
				#endif
				T.dx=-1;T.dy=0;
				if(cx!=1)
					grid[cx-1][cy].push_back(T);
				T.dx=0;T.dy=-1;
				if(cy!=1)
					grid[cx][cy-1].push_back(T);
				T.dx=0;T.dy=+1;
				if(cy!=21)
				grid[cx][cy+1].push_back(T);
				T.dx=+1;T.dy=0;
				if(cx!=21)
				grid[cx+1][cy].push_back(T);
				#ifdef HACKED
				if(!FIRE) lst=true;
				if(SUPER) T.attack=20;
				#endif
			}
			else if(GetAsyncKeyState('W')&&cx!=1)
				grid[cx][cy][pp].dx=-1,cx--,lst=false;
			else if(GetAsyncKeyState('S')&&cx!=21)
				grid[cx][cy][pp].dx=+1,cx++,lst=false;
			else if(GetAsyncKeyState('A')&&cy!=1)
				grid[cx][cy][pp].dy=-1,cy--,lst=false;
			else if(GetAsyncKeyState('D')&&cy!=21)
				grid[cx][cy][pp].dy=+1,cy++,lst=false;
			else lst=false;
		#ifdef HACKED
		}
		#endif
		int X=rand()%3-1,Y=rand()%3-1;
		#ifdef HACKED
		if(FREEZE) X=Y=0;
		#endif
		if(ex+X>6&&ex+X<16&&ey+Y>6&&ey+Y<16){
			grid[ex][ey][ee].dx=X;
			grid[ex][ey][ee].dy=Y;
			ex+=X;ey+=Y;
		}
		for(int i=1;i<=21;i++)
			for(int j=1;j<=21;j++)
				mrah[i][j]=0;
		while(1){
			int die=0;
			for(int i=1;i<=21;i++)
				for(int j=1;j<=21;j++)
					harm[i][j]=mrah[i][j];
			for(int i=1;i<=21;i++)
				for(int j=1;j<=21;j++)
					mrah[i][j]=0;
			for(int i=1;i<=21;i++)
				for(int j=1;j<=21;j++)
					for(object k:grid[i][j])
						harm[i][j]+=k.attack;
			for(int i=1;i<=21;i++)
				for(int j=1;j<=21;j++)
					for(int k=0;k<grid[i][j].size();k++){
						grid[i][j][k].health-=harm[i][j];
						grid[i][j][k].health+=grid[i][j][k].attack;
						if(grid[i][j][k].health<=0){
							if(grid[i][j][k].show=='@'){
								cout<<"LOSE"<<endl;
								while(1);
							}
							if(grid[i][j][k].show=='O'){
								cout<<"WIN"<<endl;
								while(1);
							}
							die++;
							for(int ii=max(i-grid[i][j][k].exrange,1);ii<=min(i+grid[i][j][k].exrange,21);ii++)
								for(int jj=max(j-grid[i][j][k].exrange,1);jj<=min(j+grid[i][j][k].exrange,21);jj++)
									mrah[ii][jj]+=grid[i][j][k].explode;
							grid[i][j].erase(grid[i][j].begin()+k);
							k--;
						}
					}
			if(!die) break;
		}
		for(int i=1;i<=21;i++)
			for(int j=1;j<=21;j++)
				dirg[i][j].clear();
		for(int i=1;i<=21;i++)
			for(int j=1;j<=21;j++)
				for(object k:grid[i][j])
					dirg[i+k.dx][j+k.dy].push_back(k);
		for(int i=1;i<=21;i++)
			for(int j=1;j<=21;j++)
			   	grid[i][j].clear();
		for(int i=1;i<=21;i++)
			for(int j=1;j<=21;j++)
				for(object k:dirg[i][j])
					grid[i][j].push_back(k);
	}
	return 0;
}



