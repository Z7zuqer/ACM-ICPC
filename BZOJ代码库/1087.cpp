#include<bits/stdc++.h>
using namespace std;
const int maxn=777;
int n,kk,all;
int vis[maxn],mp[maxn][maxn],cnt[maxn];
void pre(){
	for(int i=0;i<=all;i++){
		if((i&(i<<1))==0){
			vis[i]=1;
			for(int j=i;j;j>>=1)
				if(j&1)cnt[i]++;
		}
	}
	for(int i=0;i<=all;i++)if(vis[i])
		for(int j=0;j<=all;j++)if(vis[j]){
			if(((i&j)==0)&&((i&(j>>1))==0)&&((j&(i>>1))==0))	
				mp[i][j]=1;
		}
}
long long dp[11][110][maxn];
int main(){
	scanf("%d%d",&n,&kk);
	all=(1<<n)-1;
	pre();
	for(int i=0;i<=all;i++)if(vis[i])dp[1][cnt[i]][i]=1;
	for(int i=2;i<=n;i++){
		for(int u=0;u<=all;u++)if(vis[u]){
			for(int k=0;k<=all;k++)if(vis[k]){
				if(mp[k][u]){
					for(int t=cnt[u];t<=kk;t++)
						dp[i][t][u]+=dp[i-1][t-cnt[u]][k];
				}
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=all;i++)if(vis[i])ans+=dp[n][kk][i];
	cout<<ans<<endl;
}
