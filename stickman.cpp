#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
string r_pos[4]={">   ","+-  ","|   ","|   "};
string l_pos[4]={"   <","  -+","   |","   |"};
int WID=50;
string grid[10];
char rock=' ';
int bot=0;
void generate(){
	int h=1;
	for(int i=0;i<10;i++) for(int j=0;j<WID;j++) grid[i]+=" ";
	for(int i=0;i<WID;i++){
		for(int j=10-1;j>=10-h;j--) grid[j][i]=rock;
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
		if(pos[i][j]!=' ')
			grid[x+i-hx][y+j-hy]=' ';
}
void fill(int x,int y,string pos[4]){
	int hx,hy;
	for(int i=0;i<4;i++) for(int j=0;j<4;j++)
		if(pos[i][j]=='>'||pos[i][j]=='<'){
			hx=i;
			hy=j;
		}
	for(int i=0;i<4;i++) for(int j=0;j<4;j++)
		if(pos[i][j]!=' ')
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
		if(grid[x+i-hx][y+j-hy]!=' ') return false;
	}
	return true;
}
struct bul{
	int x,y,dy,da;
	bool sh;
	bul(int xx,int yy,int dd,int aa,bool ss){x=xx;y=yy;dy=dd;da=aa;sh=ss;}
};
vector<bul> buls;
struct obj{
	int pos,hx,hy,act,rel,dam,fall,hea;
	bool man;
	obj(){
		pos=0;
		hx=5;hy=0;
		act=0;
		rel=500;
		dam=10;
		hea=100;
		man=true;
	}
	void G(){
		if(clock()<=fall) return;
		if(pos==0){
			clean(hx,hy,r_pos);
			if(fits(hx+1,hy,r_pos)) hx++;
			fill(hx,hy,r_pos);
			return;
		}
		else{
			clean(hx,hy,l_pos);
			if(fits(hx+1,hy,l_pos)) hx++;
			fill(hx,hy,l_pos);
			return;
		}
	}
	void F(){
		if(clock()<act) return G();
		if(pos==0)
			buls.push_back(bul(hx+1,hy+2,1,dam,man));
		else
			buls.push_back(bul(hx+1,hy-2,-1,dam,man));
		act=clock()+rel;
		G();
	}
	void R(){
		if(pos==1){
			clean(hx,hy,l_pos);
			if(fits(hx,hy,r_pos)){
				pos=0;
				fill(hx,hy,r_pos);
			}
			else fill(hx,hy,l_pos);
			return G();
		}
		else{
			clean(hx,hy,r_pos);
			if(fits(hx,hy+1,r_pos)) fill(hx,hy+1,r_pos),hy++;
			else fill(hx,hy,r_pos);
			return G();
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
			return G();
		}
		else{
			clean(hx,hy,l_pos);
			if(fits(hx,hy-1,l_pos)) fill(hx,hy-1,l_pos),hy--;
			else fill(hx,hy,l_pos);
			return G();
		}
		G();
	}
	void U(){
		if(pos==0){
			clean(hx,hy,r_pos);
			if(fits(hx-1,hy,r_pos))
				hx--,fall=clock()+200;
			fill(hx,hy,r_pos);
			return;
		}
		else{
			clean(hx,hy,l_pos);
			if(fits(hx-1,hy,l_pos))
				hx--;
			fill(hx,hy,l_pos),fall=clock()+200;
			return;
		}
	}
};
obj A,B;
void bull(){
	for(int i=(int)(buls.size())-1;i>=0;i--){
		if(grid[buls[i].x][buls[i].y]=='*')
			grid[buls[i].x][buls[i].y]=' ';
		bool li=true;
		for(int j=buls[i].y+buls[i].dy;j<=buls[i].y+buls[i].dy*5;j++){
			if(j>=WID){
				li=false;
				break;
			}
			char c=grid[buls[i].x][j];
			if(c=='#'){
				buls.erase(buls.begin()+i);
				li=false;
				break;
			}
			if(c=='+'||c=='-'||c=='>'||c=='|'||c=='<'){
				li=false;
				if(buls[i].sh){
					B.hea-=buls[i].da;
					if(B.hea<=0) B.hea=0;
				}
				else{
					A.hea-=buls[i].da;
					if(A.hea<=0) A.hea=0;
				}
				buls.erase(buls.begin()+i);
				break;
			}
		}
		if(li){
			if(grid[buls[i].x][buls[i].y+buls[i].dy*5]==' ')
				grid[buls[i].x][buls[i].y+buls[i].dy*5]='*';
			buls[i].y+=buls[i].dy*5;
		}
	}
}
void process(){
	if(GetAsyncKeyState(32)) return A.F();
	if(GetAsyncKeyState(VK_LEFT)) return A.L();
	if(GetAsyncKeyState(VK_RIGHT)) return A.R();
	if(GetAsyncKeyState(VK_UP)) return A.U();
	return A.G();
}
void process_B(){
	if(bot==0){
		if(GetAsyncKeyState('Z')) return B.F();
		if(GetAsyncKeyState('A')) return B.L();
		if(GetAsyncKeyState('D')) return B.R();
		if(GetAsyncKeyState('W')) return B.U();
		return A.G();
	}
	if(bot==1){
		int x=rand()%5;
		if(x==0) return B.F();
		if(x==1) return B.L();
		if(x==2) return B.R();
		if(x==3) return B.U();
		if(x==4) return B.G();
	}
}
int main(){
	cout<<"Mode:"<<flush;
	cin>>bot;
	srand(unsigned(time(NULL)));
	generate();
	B.pos=1;
	for(int i=9;i>=0;i--) if(grid[i][49]==' '){
		B.hx=i-3;
		B.hy=49;
		break;
	}
	B.man=false;
	fill(A.hx,A.hy,r_pos);
	fill(B.hx,B.hy,l_pos);
	while(1){
		A.G();B.G();
		system("cls");
		cout<<A.hea<<endl<<B.hea<<endl;
		for(int i=0;i<10;i++) cout<<grid[i]<<endl;
		if(A.hea<=0){
			cout<<"A loses."<<endl;
			while(1);
		}
		if(B.hea<=0){
			cout<<"B loses."<<endl;
			while(1);
		}
		bull();
		process_B();
		process();
		Sleep(100);
	}
	return 0;
}


