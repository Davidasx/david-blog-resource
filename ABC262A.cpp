#include<bits/stdc++.h>
using namespace std;
inline int rd(){
	static char c=getchar();int fu=1,val=0;
	for(;(c<48||c>57)&&c!='-';c=getchar());
	if(c=='-') fu=-1,c=getchar();
	for(;c>=48&&c<=57;c=getchar()) val=(val<<1)+(val<<3)+(c^48);
	return val*fu;
}
int y;
int main(){
	cin>>y;
	cout<<(y+1)/4*4+2;
	return 0;
}


