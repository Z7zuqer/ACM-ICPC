#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
int a,b,n,m,ans1,ans2,ans3;
int cnt[2][maxn],vis[maxn];
vector<int>v[2][maxn];
void dfs(int now,int u){
	vis[u]=1;cnt[now][u]++;
	for(int i=0;i<v[now][u].size();i++)
		if(!vis[v[now][u][i]])
			dfs(now,v[now][u][i]);
} 
int main(){
	scanf("%d%d%d%d",&a,&b,&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[0][x].push_back(y);
		v[1][y].push_back(x);
	}
	for(int k=0;k<=1;k++)
		for(int i=0;i<n;i++){
			memset(vis,0,sizeof vis);
			dfs(k,i);
		}
	for(int i=0;i<n;i++){
		if(cnt[1][i]>n-a)ans1++;
		if(cnt[1][i]>n-b)ans2++;
		if(cnt[0][i]>b)ans3++; 
	}
	cout<<ans1<<endl<<ans2<<endl<<ans3<<endl;
}


