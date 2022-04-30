#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
struct person{
	string name;
	int hp,attack,defend,perk_attack,perk_defend,rebound,perk_rate;
	bool zombie,puppet;
}zombie;
bool operator <(person a,person b){
	return a.name<b.name;
}
person generate(string name){
	person xxx,yyy;
	for(int i=0;i<(int)(name.size());i++) if(name[i]>='A'&&name[i]<='Z')
		name[i]=(name[i]-'A'+'a');
	xxx.hp=xxx.attack=xxx.defend=xxx.perk_attack=xxx.perk_defend=xxx.rebound=0;
	xxx.perk_rate=0;
	for(int i=0;i<(int)(name.size());i++){
		xxx.hp=(xxx.hp*59+name[i])%100;
		xxx.attack=(xxx.attack*61+name[i])%100;
		xxx.defend=(xxx.attack*63+name[i])%100;
		xxx.perk_attack=(xxx.attack*67+name[i])%100;
		xxx.perk_defend=(xxx.attack*61+name[i])%100;
		xxx.rebound=(xxx.rebound*73+name[i])%100;
		xxx.perk_rate=(xxx.perk_rate*79+name[i])%100;
	}
	yyy.name=name;
	srand(998244353);
	while(xxx.hp--)
		yyy.hp=rand()%100+1100;
	while(xxx.attack--)
		yyy.attack=rand()%20+30;
	while(xxx.defend--)
		yyy.defend=rand()%10+20;
	while(xxx.perk_attack--)
		yyy.perk_attack=rand()%5+5;
	while(xxx.perk_defend--)
		yyy.perk_defend=rand()%5+5;
	while(xxx.rebound--)
		yyy.rebound=rand()%20+10;
	while(xxx.perk_rate--)
		yyy.perk_rate=rand()%10+10;
	yyy.zombie=false;
	return yyy;
}
void showinfo(person x){
	cout<<"Name: "<<x.name<<endl;
	cout<<"HP: "<<x.hp<<endl;
	cout<<"Attack: "<<x.attack<<endl;
	cout<<"Defend: "<<x.defend<<endl;
	cout<<"Rebound: "<<x.rebound<<endl;
	cout<<"Perk(attack,defend,rate): "<<x.perk_attack<<","<<x.perk_defend<<","<<x.perk_rate<<endl;
}
vector<vector<person> > play;
vector<person> group;
int win;
int winner=1;
void round(bool silent){
	srand(998244353);
	rand();
	for(int i=0;i<play.size();i++) sort(play[i].begin(),play[i].end());
	sort(play.begin(),play.end());
	int rt=(int)(play.size());
	vector<string> log;
	bool found;
	int T;
	int NUM=0;
	for(int i=0;i<play.size();i++) for(int j=0;j<play[i].size();j++)
		NUM++;
	while(1){
		if(!silent) system("cls");
		if(!silent) for(int i=0;i<play.size();i++) for(int j=0;j<play[i].size();j++){
			if(play[i][j].hp>0)
				cout<<play[i][j].name<<" (team "<<i+1<<"):"<<play[i][j].hp<<endl;
			else
				cout<<play[i][j].name<<" (team "<<i+1<<"):DEAD"<<endl;
		}
		rt=0;
		bool ooo;
		for(int i=0;i<play.size();i++){
			ooo=false;
			for(int j=0;j<play[i].size();j++) if(play[i][j].hp>0)
				ooo=true;
			if(ooo) rt++;
		}
		if(rt==1) break;
		int attacker=rand()%rt;
		found=false;
		for(int i=0;i<play.size();i++){
			for(int j=0;j<play[i].size();j++)
				if(play[i][j].hp>0){
					attacker--;
					if(attacker<0){
						attacker=i;
						found=true;
						break;
					}
				}
			if(found) break;
		}
		T=0;
		for(int j=0;j<play[attacker].size();j++)
			if(play[attacker][j].hp>0) T++;
		int player=rand()%T;
		found=false;
		for(int j=0;j<play[attacker].size();j++)
			if(play[attacker][j].hp>0){
				player--;
				if(player<0){
					player=j;
					break;
				}
			}
		int defender=rand()%(rt-1);
		found=false;
		for(int i=0;i<play.size();i++) if(i!=attacker){
			for(int j=0;j<play[i].size();j++)
				if(play[i][j].hp>0){
					defender--;
					if(defender<0){
						defender=i;
						found=true;
						break;
					}
				}
			if(found) break;
		}
		T=0;
		for(int j=0;j<play[defender].size();j++)
			if(play[defender][j].hp>0) T++;
		int aplayer=rand()%T;
		found=false;
		for(int j=0;j<play[defender].size();j++)
			if(play[defender][j].hp>0){
				aplayer--;
				if(aplayer<0){
					aplayer=j;
					break;
				}
			}
		person &x=play[attacker][player];
		person &y=play[defender][aplayer];
		if(!silent)
			log.push_back(x.name+" is attacking "+y.name);
		int drop=x.attack;
		if(rand()%100<=x.perk_rate){
			if(!silent)
				log.push_back(x.name+" uses attack perk");
			drop+=x.perk_attack*drop/100;
		}
		drop-=y.defend*drop/100;
		if(rand()%100<=y.perk_rate){
			if(!silent)
				log.push_back(y.name+" uses defend perk");
			drop-=y.perk_defend*drop/100;
		}
		y.hp-=drop;
		if(y.hp<=0){
			if(!silent)
				log.push_back(y.name+" is killed by "+x.name);
			if(rand()%100<=y.perk_rate&&rand()%100<=y.perk_rate&&!y.zombie){
				if(!silent)
					log.push_back(y.name+" becomes zombie");
				play[defender].push_back(zombie);
				play[defender].back().name=y.name+"_zombie";
			}
			if(rand()%100<=x.perk_rate&&rand()%100<=x.perk_rate&&!y.zombie){
				if(!silent)
					log.push_back(y.name+" becomes puppet");
				play[attacker].push_back(zombie);
				play[attacker].back().name=y.name+"_puppet";
			}
		}
		else if(rand()%100<=y.perk_rate){
			if(!silent)
				log.push_back(y.name+" rebounds attack");
			x.hp-=(drop*y.rebound)/100;
			if(x.hp<=0) if(!silent)
				log.push_back(x.name+" is killed by "+y.name);
		}
		for(int i=max((int)(log.size())-(25-NUM),0);i<(int)(log.size());i++)
			cout<<log[i]<<endl;
		if(!silent) Sleep(100);
	}
	for(int i=0;i<play.size();i++) for(int j=0;j<play[i].size();j++){
		if(play[i][j].hp>0){
			winner=i;
			if(!silent) cout<<"Team "<<i+1<<" ("<<play[i][0].name;
			if(!silent)  for(int kk=1;kk<play[i].size();kk++)
				cout<<","<<play[i][kk].name;
			if(!silent) cout<<") wins!"<<endl;
			return;
		}
	}
}
string rad;
queue<string> rd;
void fillrd(){
	srand(unsigned(time(NULL)));
	for(int i=0;i<=100000;i++){
		rad="";
		int len=rand()%10+5;
		for(int j=1;j<=len;j++){
			int k=rand()%36;
			if(k<26) rad+=(char)(k+'a');
			else rad+=(char)(k-26+'0');
		}
		rd.push(rad);
	}
}
string RS(){
	string ret=rd.front();
	rd.pop();
	if(rd.empty()) fillrd();
	return ret;
}
int main(){
	zombie.hp=300;zombie.attack=25;zombie.defend=15;
	zombie.perk_attack=zombie.perk_defend=5;
	zombie.rebound=0;zombie.perk_rate=15;
	zombie.zombie=true;
	string s;
	fillrd();
	while(cin>>s){
		if(s=="-"){
			if(group.size()) play.push_back(group);
			group.clear();
			continue;
		}
		if(s=="@random")
			s=RS();
		if(s=="@test"){
			int num=1000;
			cin>>s;
			if(s=="@random") s=RS();
			system("cls");
			showinfo(generate(s));
			cout<<"Testing has started."<<endl;
			win=0;
			int lst=0;
			srand(unsigned(time(NULL)));
			string tmp;
			person S;
			S=generate(s);
			for(int ti=1;ti<=1000;ti++){
				for(int i=lst+1;i<=num;i++){
					play.clear();
					group.clear();
					tmp=RS();
					group.push_back(generate(tmp));
					play.push_back(group);
					group.clear();
					group.push_back(S);
					play.push_back(group);
					round(true);
					if(play[winner][0].name==s) win++;
				}
				system("cls");
				showinfo(S);
				cout<<"Testing has started."<<endl;
				cout<<"Result after "<<num<<" rounds:"<<endl;
				cout<<win<<" wins, "<<num-win<<" losses."<<endl;
				cout<<"Rate:"<<(win*100)/num<<" percent."<<endl;
				lst=num;
				num+=1000;
			}
			if(win*100<30*num) cout<<"Level: Bad"<<endl;
			else if(win*100<50*num) cout<<"Level: Normal"<<endl;
			else if(win*100<80*num) cout<<"Level: Good"<<endl;
			else if(win*100<90*num) cout<<"Level: Excellent"<<endl;
			else cout<<"Level: Perfect"<<endl;
			while(1);
		}
		group.push_back(generate(s));
	}
	if(group.size()) play.push_back(group);
	if(play.size()==1){
		group=play[0];
		play.clear();
		vector<person> vp;
		for(int i=0;i<group.size();i++){
			vp.push_back(group[i]);
			play.push_back(vp);
			vp.clear();
		}
	}
	round(false);
	return 0;
}
