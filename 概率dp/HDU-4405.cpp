#include<bits/stdc++.h>
using namespace std;
double dp[1000100];
int fa[1000100],vis[1000100];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)&&n){
		for(int i=0;i<=n;i++)dp[i]=0;
		dp[0]=1;
		for(int i=0;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			if(a>b)swap(a,b);
			fa[find(a)]=fa[find(b)];
		}
		for(int i=1;i<=n;i++)if(find(i)!=i)vis[i]=0;else vis[i]=0;
		for(int i=0;i<=n;i++){
			if(vis[i])continue;
			int now=find(i),all=0;
			for(int j=1;j<=6;j++){
				int nex=find(now+j);
				if(nex>n||nex==0)break;
				//cout<<now<<" "<<j<<" "<<nex<<endl;
				dp[find(now+j)]+=(1.0/6)*(dp[now]);
			}
		}
		double ans=0;
		for(int i=0;i<=n;i++)cout<<dp[i]<<" "<<i<<endl;;cout<<endl;
		ans=dp[n-1];
		ans+=dp[n-2]*(5.0/6);
		ans+=dp[n-3]*(4.0/6);
		ans+=dp[n-4]*(3.0/6);
		ans+=dp[n-5]*(2.0/6);
		ans+=dp[n-6]*(1.0/6);
		printf("%.7lf\n",ans);
	}
}


