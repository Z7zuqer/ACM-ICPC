#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	srand(time(0));
	scanf("%d",&T);
	int ans=859;//..
	for(int i=1;i<=T;i++){
		if(ans&1)puts("YES");
		else puts("NO"); 
		ans>>=1; 
	}
}


