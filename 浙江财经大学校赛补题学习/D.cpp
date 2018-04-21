#include<bits/stdc++.h>
using namespace std;
int cas=1;
void print(int k){
	if(k)printf("Case #%d: Bob\n",cas++);
	else printf("Case #%d: Alice\n",cas++);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int l,r,x;
		scanf("%d%d%d",&l,&x,&r);
		int lenl=x-l,lenr=r-x;
		//1   bob win 
		//0   alice win
		if(lenl==0&&lenr==0)print(1);
		else if(lenl==0||lenr==0)print(0);
		else if(lenl==1){
			if(lenr==1)print(1);
			else if(lenr==2)print(0);
			else print(0);
		}
		else if(lenl==2){
			if(lenr==1)print(0);
			else if(lenr==2)print(1);
			else print(0);
		}
		else {
			if(lenr==1)print(0);
			else if(lenr==2)print(0);
			else {
				if(lenl==lenr)print(1);
				else print(0);
			}
		}
	} 
}


