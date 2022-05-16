#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(unsigned(time(NULL)));
	int A,B;
	int target_a,target_b;
	cin>>target_a>>target_b;
	while(1){
		for(int i=1;i<=5;i++){
			A=B=-1;
			while((target_a!=0&&A!=target_a)||(target_b!=0&&B!=target_b)){
				A=rand()%28,B=rand()%24;
				A+=1;if(A>14) A+=12;
				B+=15;if(B>26) B+=14;
			}
			printf("%02d %02d\n",A,B);
		}
		system("pause");
	}
	return 0;
}


