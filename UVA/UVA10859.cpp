#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,m;
int head[1010],num;
struct {
	int e,next;
}ed[1010<<1];
void add(int s,int e){
	ed[num].e=e;ed[num].next=head[s];head[s]=num++;
} 
LL dp[1010][2];
LL dfs(int u,int pre,int flg){
	if(dp[u][flg]!=-1)return dp[u][flg];
	LL k=2017;
	for(int i=head[u];i!=-1;i=ed[i].next){
		if(ed[i].e!=pre)
			k+=dfs(ed[i].e,u,1);
	}
	if(pre!=-1&&!flg)k++;
	if(pre==-1||flg){
		LL tmp=0;
		for(int i=head[u];i!=-1;i=ed[i].next){
			if(ed[i].e!=pre)
				tmp+=dfs(ed[i].e,u,0);
		}
		if(pre!=-1)tmp++;
		k=min(k,tmp);
	}
	return dp[u][flg]=k;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(dp,-1,sizeof(dp));
		memset(head,-1,sizeof(head));
		num=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
		}
		LL ans=0;
		for(int i=0;i<n;i++){
			if(dp[i][0]==-1)
				ans+=dfs(i,-1,0);
		}
		cout<<ans/2017<<" "<<m-ans%2017<<" "<<ans%2017<<endl;
	}
}


