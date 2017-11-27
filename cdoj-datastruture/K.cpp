#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=100100;
int fa[maxn][2],vis[maxn]; 
LL A[maxn],sum[maxn],req[maxn];
int find(int x,int u){
	return fa[x][u]==x?fa[x][u]:fa[x][u]=find(fa[x][u],u);
}
void uni(int x,int y,int v){
	int fx=find(fa[x][v],v);
	int fy=find(fa[y][v],v);
	if(v)fa[min(fx,fy)][v]=max(fx,fy),fa[max(fx,fy)][v^1]=min(fx,fy);
	else fa[max(fx,fy)][v]=min(fx,fy),fa[min(fx,fy)][v^1]=max(fx,fy);
	//fa[fy][v]=fx;
}
LL ans[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&A[i]);	
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+A[i];
	for(int i=1;i<=n;i++)scanf("%lld",&req[i]);
	for(int i=1;i<=n;i++)fa[i][0]=fa[i][1]=i;
	LL r=0;//vis[req[n]]=1;
	//cout<<ans<<endl;
	for(int i=n;i>=1;i--){
		ans[i]=r;
		//printf("%lld\n",ans);
		if(vis[req[i]-1]&&req[i]-1>=1)uni(req[i]-1,req[i],0);
		if(vis[req[i]+1]&&req[i]+1<=n)uni(req[i],req[i]+1,1);
		int sta=find(req[i],0),end=find(req[i],1);
		r=max(r,sum[end]-sum[sta-1]);
		vis[req[i]]=1;
		//printf("%lld\n",ans);
	}
	for(int i=1;i<=n;i++)printf("%lld\n",ans[i]);
}
/*
5
1 1 1 1 1
1 3 5 4 2
*/

