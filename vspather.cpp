#include<bits/stdc++.h>
using namespace std;
inline int rd(){
	static char c=getchar();int fu=1,val=0;
	for(;(c<48||c>57)&&c!='-';c=getchar());
	if(c=='-') fu=-1,c=getchar();
	for(;c>=48&&c<=57;c=getchar()) val=(val<<1)+(val<<3)+(c^48);
	return val*fu;
}
void parsepath(){
	string s,li,in;
	ifstream fin("C:\\vspath.cpp");
	ifstream fin2("C:\\vslib.cpp");
	ifstream fin3("C:\\vsinclude.cpp");
	getline(fin,s);
	getline(fin2,li);
	getline(fin3,in);
	if(s[(int)(s.size())-1]!=';') s+=";";
	if(li[(int)(li.size())-1]!=';') li+=";";
	if(in[(int)(in.size())-1]!=';') in+=";";
	string tt="";
	string cur="1";
	string realpath="";
	bool inpt=false,inli=false,inin=false;
	for(int i=0;i<(int)(s.size());i++){
		tt+=s[i];
		if(s[i]==';'){
			if(tt=="%BEGIN_VSPATH%;") inpt=true;
			bool ok=false;
			if((int)(tt.size())>=6){
				for(int j=0;j<=(int)(tt.size())-6;j++)
					if(tt.substr(j,6)=="Visual"){
						ok=true;
						break;
					}
			}
			if((int)(tt.size())>=4){
				for(int j=0;j<=(int)(tt.size())-4;j++)
					if(tt.substr(j,4)=="Kits"){
						ok=true;
						break;
					}
			}
			if(ok&&!inpt){
				if((int)(tt.size())+(int)(realpath.size())<=1000)
					realpath+=tt;
				else{
					system(("setx VS_PATH"+cur+" \""+realpath+"\"").data());
					if(cur=="2")
						system(("setx VSP_PATH"+cur+" \""+realpath+"\"").data());
					realpath=tt;
					cur[0]++;
				}
			}
			if(tt=="%END_VSPATH%;") inpt=false;
			tt="";
		}
	}
	system(("setx VS_PATH"+cur+" \""+realpath+"\"").data());
	if(cur=="2")
		system(("setx VSP_PATH"+cur+" \""+realpath+"\"").data());
	cur[0]++;
	while(cur!="5"){
		system(("setx VS_PATH"+cur+" \"\"").data());
		cur[0]++;
	}
	tt="";
	realpath="";
	for(int i=0;i<(int)(li.size());i++){
		tt+=li[i];
		if(li[i]==';'){
			if(tt=="%BEGIN_VSLIB%;") inli=true;
			if(!inli) realpath+=tt;
			if(tt=="%END_VSLIB%;") inli=false;
			tt="";
		}
	}
	system(("setx LIB \"%BEGIN_VSLIB%;"+realpath+"%END_VSLIB%;\"").data());
	tt="";
	realpath="";
	for(int i=0;i<(int)(in.size());i++){
		tt+=in[i];
		if(in[i]==';'){
			if(tt=="%BEGIN_VSINCLUDE%;") inin=true;
			if(!inin) realpath+=tt;
			tt="";
			if(tt=="%END_VSINCLUDE%;") inin=false;
		}
	}
	system(("setx INCLUDE \"%BEGIN_VSINCLUDE%;"+realpath+"%END_VSINCLUDE%;\"").data());
}
int main(){
	system("echo %PATH% > C:\\vspath.cpp");
	system("echo %LIB% > C:\\vslib.cpp");
	system("echo %INCLUDE% > C:\\vsinclude.cpp");
	parsepath();
	return 0;
}

