#include<bits/stdc++.h>
using namespace std;
#define LL long long
void dfs(LL k,int now){
	if(k==1){
		printf("%d\n",now);
		return ;
	}
	if(k&1)dfs(3*k+1,now+1);
	else dfs(k/2,now+1);
}
int main(){
	LL n;
	scanf("%lld",&n);
	dfs(n,1);
}


