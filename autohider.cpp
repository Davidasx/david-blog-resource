#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
vector<pair<HWND,string> > lst;
int main(){
	system("title xxx");
	HWND hh=FindWindow(NULL,"xxx"),tt;
	if(!hh) hh=FindWindow(NULL,"π‹¿Ì‘±:  xxx");
	ShowWindow(hh,SW_HIDE); 
	while(1){
		if(GetAsyncKeyState(VK_LCONTROL)&&GetAsyncKeyState('H')){
			string s;
			tt=GetForegroundWindow();
			ShowWindow(tt,SW_HIDE);
			lst.push_back(make_pair(tt,s));
			Sleep(500);
			continue;
		}
		if(GetAsyncKeyState(VK_LCONTROL)&&GetAsyncKeyState('Q')){
			system("cls");
			ShowWindow(hh,SW_SHOW);
			for(int i=0;i<(int)(lst.size());i++){
				printf("%3d)  %s\n",i,lst[i].second.data());
			}
			int x;
			cin>>x;
			ShowWindow(lst[x].first,SW_SHOW);
			lst.erase(lst.begin()+x);
			ShowWindow(hh,SW_HIDE); 
		}
	}
	return 0;
}


