#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
vector<string> lines;
set<string> used;
string base;
void expand(string filename){
	if(used.count(filename)) return;
	ifstream fin(filename.data());
	if(!fin){
		cout<<"File \""+filename+"\" not found."<<endl;
		exit(3);
	}
	string ss;
	while(getline(fin,ss)){
		if((int)(ss.size())>=17){
			if(ss.substr(0,17)=="#include<atcoder/"||ss.substr(0,17)=="#include\"atcoder/"){
				string subfile=base+ss.substr(9);
				subfile.erase(subfile.begin()+(int)(subfile.size())-1);
				for(int i=0;i<(int)(subfile.size());i++)
					if(subfile[i]=='/')
						subfile[i]='\\';
				expand(subfile);
				continue;
			}
		}
		if((int)(ss.size())>=18){
			if(ss.substr(0,18)=="#include <atcoder/"||ss.substr(0,18)=="#include \"atcoder/"){
				string subfile=base+ss.substr(10);
				subfile.erase(subfile.begin()+(int)(subfile.size())-1);
				for(int i=0;i<(int)(subfile.size());i++)
					if(subfile[i]=='/')
						subfile[i]='\\';
				expand(subfile);
				continue;
			}
		}
		lines.push_back(ss);
	}
	cout<<"Expanded: "<<filename<<endl;
}
int main(int argc,char** argv){
	if(argc<3){
		cout<<"Usage: expander.exe [FILE] [OUTPUT]"<<endl;
		return 1;
	}
	system("echo %CPLUS_INCLUDE_PATH% > EXPANDER_BASE");
	ifstream bin("EXPANDER_BASE");
	bin>>base;
	bin.close();
	system("del EXPANDER_BASE");
	if(base[0]=='%'){
		system("echo %ACL_BASE% > EXPANDER_BASE");
		ifstream bbin("EXPANDER_BASE");
		bbin>>base;
		bbin.close();
		system("del EXPANDER_BASE");
		if(base[0]=='%'){
			cout<<"ACL not found. Please set %ACL_BASE% to the path to ACL."<<endl;
			return 2;
		}
	}
	cout<<"Found ACL."<<endl;
	if(base[base.size()-1]!='\\') base+="\\";
	string file=argv[1],output=argv[2];
	expand(file);
	ifstream ofin(output.data());
	if(ofin){
		ofin.close();
		string cmd="del "+output;
		system(cmd.data());
	}
	ofstream fout(output.data());
	for(int i=0;i<lines.size();i++)
		fout<<lines[i]<<endl;
	fout.close();
	return 0;
}


