#include<bits/stdc++.h>
using namespace std;
int main(int argc,char** argv){
	if(argc<=1){
		cout<<"ERROR : No filename."<<endl;
		cout<<"Usage:msvc.exe [FILENAME] (options)"<<endl;
		return 1;
	}
	string code,prog="?",obje;
	string s;
	string opt="";
	for(int i=1;i<argc;i++){
		s=argv[i];
		if(s=="-o"){
			i++;
			s=argv[i];
			prog=s;
			continue;
		}
		if(s[0]=='-'||s[0]=='/'){
			s[0]='/';
			for(int i=0;i<(int)(s.size());i++) if(s[i]=='=')
				s[i]=':';
			opt+=" ";opt+=s;
			continue;
		}
		code=s;
	}
	obje=code;
	while((int)(obje.size())&&obje[(int)(obje.size())-1]!='.')
		obje.erase(obje.begin()+((int)(obje.size())-1));
	if(obje=="") obje=code+".";
	obje+="obj";
	string oprog=code;
	while((int)(oprog.size())&&oprog[(int)(oprog.size())-1]!='.')
		oprog.erase(oprog.begin()+((int)(oprog.size())-1));
	if(oprog=="") oprog=code+".";
	oprog+="exe";
	if(prog=="?") prog=oprog;
	ifstream fin(prog.data());
	if(fin){
		fin.close();
		system(("del "+prog).data());
	}
	int rt=system(("cl "+code+opt).data());
	if(rt) return rt;
	if(prog!=oprog){
		system(("copy "+oprog+" "+prog).data());
		system(("del "+oprog).data());
	}
	system(("del "+obje).data());
	return 0;
}
