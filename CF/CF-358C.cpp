#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=1e5+7*13;
vector<pair<int,LL> >v[maxn];
LL A[maxn],ans;
int top=0,vis[maxn];
void dfs(int u,int pre,LL dist){
	//cout<<dist<<endl;
	if(dist>A[u])return ;
	vis[u]=1;
	for(int i=0;i<v[u].size();i++){
		if(!vis[v[u][i].first])dfs(v[u][i].first,u,dist<=0?v[u][i].second:v[u][i].second+dist);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&A[i]);
	for(int i=1;i<n;i++){
		int y;LL z;
		scanf("%d%lld",&y,&z);
		v[i+1].push_back({y,z});
		v[y].push_back({i+1,z});
	}
	dfs(1,-1,0*1LL);
	for(int i=1;i<=n;i++)
		if(!vis[i])ans++;
	cout<<ans<<endl;
}


