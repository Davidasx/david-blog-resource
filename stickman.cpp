#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
string r_pos[4]={">   ","+-  ","|   ","|   "};
string l_pos[4]={"   <","  -+","   |","   |"};
int WID=50;
string grid[10];
void generate(){
	int h=1;
	for(int i=0;i<10;i++) for(int j=0;j<WID;j++) grid[i]+=" ";
	for(int i=0;i<WID;i++){
		for(int j=10-1;j>=10-h;j--) grid[j][i]='#';
		int delta=rand()%3-1;
		h+=delta;
		if(h>3) h=3;
		if(h<1) h=1; 
	}
}
void clean(int x,int y,string pos[4]){
	int hx,hy;
	for(int i=0;i<4;i++) for(int j=0;j<4;j++)
		if(pos[i][j]=='>'||pos[i][j]=='<'){
			hx=i;
			hy=j;
		}
	for(int i=0;i<4;i++) for(int j=0;j<4;j++)
		if(pos[i][j]!=' '&&grid[x+i-hx][y+j-hy]!='*')
			grid[x+i-hx][y+j-hy]=' ';
}
void fill(int x,int y,string pos[4]){
	cout<<"FILL "<<x<<" "<<y<<" "<<endl;
	for(int i=0;i<4;i++) cout<<pos[i]<<endl;
	int hx,hy;
	for(int i=0;i<4;i++) for(int j=0;j<4;j++)
		if(pos[i][j]=='>'||pos[i][j]=='<'){
			hx=i;
			hy=j;
		}
	for(int i=0;i<4;i++) for(int j=0;j<4;j++)
		if(pos[i][j]!=' '&&grid[x+i-hx][y+j-hy]!='*')
			grid[x+i-hx][y+j-hy]=pos[i][j];
}
bool fits(int x,int y,string pos[4]){
	int hx,hy;
	for(int i=0;i<4;i++) for(int j=0;j<4;j++)
		if(pos[i][j]=='>'||pos[i][j]=='<'){
			hx=i;
			hy=j;
		}
	for(int i=0;i<4;i++) for(int j=0;j<4;j++){
		if(pos[i][j]==' ') continue;
		if(x+i-hx<0||x+i-hx>=10) return false;
		if(y+j-hy<0||y+j-hy>=WID) return false;
		if(grid[x+i-hx][y+j-hy]!=' '&&grid[x+i-hx][y+j-hy]!='*') return false;
	}
	return true;
}
struct bul{
	int x,y,dy,da;
	bul(int xx,int yy,int dd,int aa){x=xx;y=yy;dy=dd;da=aa;}
};
vector<bul> buls;
struct obj{
	int pos,hx,hy,act,rel,dam;
	obj(){
		pos=0;
		hx=5;hy=0;
		act=0;
		rel=500;
		dam=1;
	}
	void F(){
		if(clock()<act) return;
		if(pos==0)
			buls.push_back(bul(hx+1,hy+2,1,dam));
		else
			buls.push_back(bul(hx+1,hy-2,1,dam));
		act=clock()+rel;
	}
	void R(){
		if(pos==1){
			clean(hx,hy,l_pos);
			if(fits(hx,hy,r_pos)){
				pos=0;
				fill(hx,hy,r_pos);
			}
			else fill(hx,hy,l_pos);
			return;
		}
		else{
			clean(hx,hy,r_pos);
			if(fits(hx,hy+1,r_pos)) fill(hx,hy+1,r_pos),hy++;
			else fill(hx,hy,r_pos);
			return;
		}
	}
	void L(){
		if(pos==0){
			clean(hx,hy,r_pos);
			if(fits(hx,hy,l_pos)){
				pos=1;
				fill(hx,hy,l_pos);
			}
			else fill(hx,hy,r_pos);
			return;
		}
		else{
			clean(hx,hy,l_pos);
			if(fits(hx,hy-1,l_pos)) fill(hx,hy-1,l_pos),hy--;
			else fill(hx,hy,l_pos);
			return;
		}
	}
	void G(){
		if(pos==0){
			clean(hx,hy,r_pos);
			while(fits(hx,hy,r_pos)) hx++;
			hx--;
			return;
		}
		else{
			clean(hx,hy,l_pos);
			while(fits(hx,hy,l_pos)) hx++;
			hx--;
			return;
		}
	}
	void U(){
		if(pos==0){
			clean(hx,hy,r_pos);
			if(fits(hx+1,hy,r_pos)){
				hx++;
				fill(hx+1,hy,r_pos);
			}
			else fill(hx,hy,r_pos);
			return;
		}
		else{
			clean(hx,hy,l_pos);
			if(fits(hx+1,hy,l_pos)){
				hx++;
				fill(hx+1,hy,l_pos);
			}
			else fill(hx,hy,l_pos);
			return;
		}
	}
};
obj A,B;
void process(){
	if(GetAsyncKeyState(32)){
		A.F();
		A.G();
		return;
	}
	if(GetAsyncKeyState(VK_LEFT)){
		A.L();
		A.G();
		return;
	}
	if(GetAsyncKeyState(VK_RIGHT)){
		A.R();
		A.G();
		return;
	}
	if(GetAsyncKeyState(VK_UP)) return A.U();
	return A.G();
}
int main(){
	srand(unsigned(time(NULL)));
	generate();
	B.pos=1;
	for(int i=9;i>=0;i--) if(grid[i][49]==' '){
		B.hx=i-3;
		B.hy=49;
		break;
	}
	fill(A.hx,A.hy,r_pos);
	fill(B.hx,B.hy,l_pos);
	while(1){
		A.G();B.G();
		system("cls");
		for(int i=0;i<10;i++) cout<<grid[i]<<endl;
		process();
		Sleep(100);
	}
	return 0;
}


