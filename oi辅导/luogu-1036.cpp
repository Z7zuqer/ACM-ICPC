#include<bits/stdc++.h>
using namespace std;
int A[100],vis[200],n,k,ans;
int check(int x){
	if(x==2)return 1;
	int div=3+ceil(sqrt(x));
	for(int i=2;i<=div;i++)if(x%i==0&&i<x)return 0;
	return 1;
}
void dfs(int now,int sum){
	if(now>k){
		//cout<<sum<<endl;
		if(check(sum))ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(now+1,sum+A[i]);
			vis[i]=0;
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	dfs(1,0);
	int r=1;
	for(int i=1;i<=k;i++)r*=i;
	printf("%d\n",ans/r);
}


