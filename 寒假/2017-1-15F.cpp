#include<bits/stdc++.h>
using namespace std;
const int maxn=401;
int n,w,k;
int A[maxn][maxn];
int col[maxn][maxn];
int dp[maxn][maxn];
int path[maxn][maxn];//1 up 2 left
struct node{
	int a,b;
};
vector<node>v;
int count(int u){
	int ans=0;
	while(u){
		ans+=u&1;
		u>>=1;
	}
	return ans;
}
void print(int now,int siz){
	if(now==siz-1){
		printf("%d %d ",v[now].a,v[now].b);
		return ;
	}
	print(now+1,siz);
	printf("%d %d ",v[now].a,v[now].b);
}
int main(){
	scanf("%d%d%d",&n,&k,&w);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&A[i][j]);
	int maxm=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&col[i][j]);
	int ans=51,res=0;
	/*
	memset(dp,0x3f,sizeof(dp));
	int num=1<<(maxm);
	dp[1][1][1<<(col[1][1]-1)]=A[1][1];
	for(int i=2;i<=n;i++){
		int u=1<<(col[1][i]-1);
		for(int k=0;k<num;k++){
			dp[1][i][k|u]=min(dp[1][i-1][k]+A[1][i],dp[1][i][k|u]);
			path[1][i][k|u]=2;
			path[1][i][k|u]+=k*10;		
		}
	}
	for(int i=2;i<=n;i++){
		int u=1<<(col[i][1]-1);
		for(int k=0;k<num;k++){
			dp[i][1][k|u]=min(dp[i-1][1][k]+A[i][1],dp[i][1][k|u]);
			path[i][1][k|u]=2;
			path[i][1][k|u]+=k*10;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			int u=1<<(col[i][j]-1);
			for(int k=0;k<num;k++){
				if(dp[i-1][j][k]+A[i][j]<dp[i][j][k|u]){
					dp[i][j][k|u]=dp[i-1][j][k]+A[i][j];
					path[i][j][k|u]=1;
					path[i][j][k|u]+=k*10;
				}	
				else if(dp[i][j-1][k]+A[i][j]<dp[i][j][k|u]){
					dp[i][j][k|u]=dp[i][j-1][k]+A[i][j];
					path[i][j][k|u]=2;
					path[i][j][k|u]+=k*10; 
				}		
			}
		}
	}
	*/
	for(int sta=0;sta<(1<<k);sta++){
		dp[1][1]=(sta&(1<<(col[1][1]-1)))?A[1][1]:-1;
		if(dp[1][1]==-1)continue; 
		for(int i=2;i<=n;i++){
			dp[1][i]=dp[i][1]=1e9+1;
			if((sta&(1<<(col[i][1]-1)))&&dp[i-1][1]!=-1&&dp[i-1][1]+A[i][1]<dp[i][1])dp[i][1]=dp[i-1][1]+A[i][1],path[i][1]=1;
			if((sta&(1<<(col[1][i]-1)))&&dp[1][i-1]!=-1&&dp[1][i-1]+A[1][i]<dp[1][i])dp[1][i]=dp[1][i-1]+A[1][i],path[1][i]=2;
			if(dp[1][i]==1e9+1)dp[1][i]=-1;
			if(dp[i][1]==1e9+1)dp[i][1]=-1;
		}
		for(int i=2;i<=n;i++)
			for(int j=2;j<=n;j++){
				dp[i][j]=1e9+1;
				if((sta&(1<<(col[i][j]-1)))&&dp[i-1][j]!=-1&&dp[i-1][j]+A[i][j]<dp[i][j])dp[i][j]=dp[i-1][j]+A[i][j],path[i][j]=1;
				if((sta&(1<<(col[i][j]-1)))&&dp[i][j-1]!=-1&&dp[i][j-1]+A[i][j]<dp[i][j])dp[i][j]=dp[i][j-1]+A[i][j],path[i][j]=2;
				if(dp[i][j]==1e9+1)dp[i][j]=-1;
			}
		if(dp[n][n]!=-1&&dp[n][n]<=w&&ans>count(sta)){
			v.clear();
			v.push_back({n,n});
			while(v.back().a!=1||v.back().b!=1){
				int x=v.back().a,y=v.back().b;
				if(path[x][y]==1)v.push_back({x-1,y});
				else if(path[x][y]==2)v.push_back({x,y-1});
			}
			ans=count(sta);
		}
	}
	if(ans==51)printf("-1\n");
	else {
		printf("%d\n",ans);
		print(0,v.size());
		printf("\n");
	}
}


