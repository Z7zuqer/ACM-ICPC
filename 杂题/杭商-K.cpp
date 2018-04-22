#include<bits/stdc++.h>
using namespace std;
const int maxn=13;
int mp[maxn][maxn],A[maxn],vis[maxn][maxn];
int n,m,t,stav,endv,maxv; 
void dfs(int x,int rest,int now){
	if(x==endv)maxv=max(maxv,now);
	for(int i=1;i<=n;i++){
		if(rest>=mp[x][i]&&mp[x][i]!=-1&&!vis[x][i]){
			int res=A[i];A[i]=0;
			vis[x][i]=1;
			dfs(i,rest-mp[x][i],now+res);
			vis[x][i]=0;
			A[i]=res;
		}
	}
}
int main(){
	while(scanf("%d%d%d%d%d",&n,&m,&t,&stav,&endv)==5){
		memset(mp,-1,sizeof mp);
		memset(vis,0,sizeof vis);
		maxv=0;
		stav++;endv++;
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		for(int i=1;i<=m;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			mp[x+1][y+1]=mp[y+1][x+1]=z;
		}
		int res=A[stav];A[stav]=0;
		dfs(stav,t,res);
		printf("%d\n",maxv);
	}
}


