#include<bits/stdc++.h>
using namespace std;
int work(int x){
	int ans=x;
	while(x){
		ans+=x%10;
		x/=10;
	}
	return ans;
}
int vis[10000000+7],A[5010];
vector<int>v;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		v.push_back(i);
		int pre=i;
		while(pre<=n){
			pre=work(pre);
			if(vis[pre]||pre>n)break;
			vis[pre]=1;
		}
	}
	for(int i=1;i<=k;i++)scanf("%d",&A[i]);
	printf("%d\n",v.size());
	for(int i=1;i<=k;i++)printf("%d ",v[A[i]-1]);puts("");
}


