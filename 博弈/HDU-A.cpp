#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		int rem=n%(k+2);
		if(rem==0)puts("Tang");
		else puts("Jiang");
	}
}


