#include<bits/stdc++.h>
using namespace std;
int main(){
	int s,x;
	scanf("%d%d",&s,&x);
	double now=0,v=7;
	while(now<s-x){
		now+=v;
		if(now>=s-x){
			v*=0.98;
			break;
		}
		v*=0.98;
	}
	if(now+v>s+x)puts("n");
	else puts("y");
}


