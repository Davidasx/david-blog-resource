#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include<queue>
using namespace std;
char x[2]="";
string ver1=" Running.Press any key to pause. ";
string ver2="Paused.Press any key to continue.";
string ver=ver2;
vector<pair<int,int> > q;
COORD xx;
void cursorpos(int px,int py){
	xx.X=px;xx.Y=py;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xx);
}
void uplow(){printf("+-----------+\n");}
void padding(){
	for(int j=1;j<=((int)(ver.size())-13)/2;j++) printf(" ");
}
void empty(){printf("|           |\n");}
void base(){
	padding();printf("    /   \\    \n");
	padding();printf("   +-----+   \n");
}
int main(){
	srand(unsigned(time(NULL)));
	int A,B;
	int tar_a,tar_b;
	cin>>tar_a>>tar_b;
	system("cls");
	printf("%s\n",ver.data());
	padding();
	uplow();
	for(int i=0;i<5-(int)(q.size());i++){
		padding();
		empty();
	}
	padding();
	uplow();
	base();
	while(1){
		ver=ver1;
		while(!_kbhit()){
			A=rand()%28,B=rand()%24;
			A+=1;if(A>14) A+=12;
			B+=15;if(B>26) B+=14;
			while((tar_a!=0&&A!=tar_a)||(tar_b!=0&&B!=tar_b)){
				A=rand()%28,B=rand()%24;
				A+=1;if(A>14) A+=12;
				B+=15;if(B>26) B+=14;
			}
			q.push_back(make_pair(A,B));
			if((int)(q.size())>5) q.erase(q.begin());
			cursorpos(0,0);
			printf("%s\n",ver.data());
			padding();
			uplow();
			for(int i=0;i<(int)(q.size());i++){
				padding();
				printf("|   %02d %02d   |\n",q[i].first,q[i].second);
			}
			for(int i=0;i<5-(int)(q.size());i++){
				padding();
				empty();
			}
			padding();
			uplow();
			base();
			Sleep(50);
		}
		ver=ver2;
		system("cls");
		printf("%s\n",ver.data());
		padding();
		uplow();
		for(int i=0;i<(int)(q.size());i++){
			padding();
			printf("|   %02d %02d   |\n",q[i].first,q[i].second);
		}
		for(int i=0;i<5-(int)(q.size());i++){
			padding();
			empty();
		}
		padding();
		uplow();
		base();
		system("pause > nul");
	}
	return 0;
}


