#include<bits/stdc++.h>
using namespace std;
#define MAX 11
string sentence[MAX+2],use[MAX+2],ans,sen,name;
int len,seed,cur,pp,sc;
bool saying[MAX+2];
void detect(){
	for(int i=0;i<MAX;i++) saying[i]=false;
	for(int i=0;i<MAX;i++)
		if(sentence[i][0]>='A'&&sentence[i][0]<='Z'&&sentence[i][1]!=' ')
			saying[i]=true;
}
void build(){
	sentence[0]="\n   ";
	sentence[1]="the key of $NAME$ is how to write $NAME$.";
	sentence[2]="I believe,";
	sentence[3]="this inspired me,";
	sentence[4]="Spain once said unknowingly,you know where your shoes are tight.";
	sentence[5]="Africa once said,the most flexible person can't see his own backbone.";
	sentence[6]="Greece onece said unknowingly,the hardest thing to do is to know oneself.";
	sentence[7]="so,";
	sentence[8]="after the discussions above ";
	sentence[9]="we all know,if there is meaning,then it must be considered carefully.";
	sentence[10]="because of this,";
	detect();
}
void replace(){
	for(int i=0;i<MAX;i++){
		use[i]="";
		for(int j=0;j<sentence[i].size();j++){
			if(j+6<=sentence[i].size()&&sentence[i].substr(j,6)=="$NAME$")
				use[i]+=name,j+=5;
			else use[i]+=sentence[i][j];
		}
	}
}
void getarticle(){
	build();
	cout<<"Name:"<<flush;getline(cin,name);
	cout<<"Length:"<<flush;cin>>len;
	if(len<500){
		cout<<"Not less than 500 letters!"<<endl;
		return;
	}
	replace();
	srand(unsigned(time(NULL)));
	seed=rand();
	string ss;
	cout<<"Seed(enter x to use "<<seed<<"):"<<flush;
	cin>>ss;
	if(ss!="x"){
		seed=0;
		for(int i=0;i<(int)(ss.size());i++) seed=(seed*10+ss[i]-'0');
	}
	system("cls");
	cout<<"Name:"<<name<<endl;
	cout<<"Length:"<<len<<endl;
	cout<<"Seed:"<<seed<<endl;
	cout<<"Generating..."<<flush;
	srand(unsigned(seed));
	cur=rand()%(MAX-1)+1;
	ans="  ";
	string cname=name;
	int pp;
	for(int i=0;i<(int)(cname.size());i++){
		if(cname[i]=='\t'||cname[i]==' ') cname[i]='_';
	}
	while(1){
		sen+=use[cur];
		if(use[cur][use[cur].size()-1]=='.'||use[cur][use[cur].size()-1]=='?'){
			if(saying[cur]){
				pp=rand()%2;
				if(pp==0) sen+=" This made me think deeply.";
				if(pp==0) sen+=" Although this saying is short,it made me wonder.";
			}
			if((int)(ans.size())+1+(int)(sen.size())>len){
				cout<<"OK!"<<endl;
				ofstream fout((cname+".txt").data());
				fout<<ans<<endl;
				fout.close();
				system((cname+".txt").data());
				return;
			}
			ans+=" ";
			for(int t=0;t<(int)(sen.size());t++) if(sen[t]!=' '&&sen[t]!='\n'){
				if(sen[t]>='a'&&sen[t]<='z') sen[t]-='a',sen[t]+='A';
				break;
			}
			ans+=sen;
			sc+=(int)(sen.length());
			sen="";
			if(sc>=800){
				sc=0;
				cur=0;
				continue;
			}
		}
		pp=rand()%(MAX-1)+1;
		cur=pp;
	}
}
int main(){
	getarticle();
	return 0;
}

