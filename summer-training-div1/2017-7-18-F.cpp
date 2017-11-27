#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=100000+107;
struct node{
	LL e,r,t;
};
vector<node>v[maxn];
LL tr[maxn];
void add(int x,LL v){
	while(x<maxn){
		tr[x]+=v;
		x+=x&-x;
	}
}
LL getans(int x){
	LL ans=0;
	while(x){
		ans+=tr[x];
		x-=x&-x;
	}
	return ans;
}
LL R[maxn],T[maxn],before[maxn],ans[maxn];
void dfs(int u,int pre){
	before[u]=getans(R[u]-1);
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i].e;
		dfs(e,u);
		add(R[e],T[e]);
	}
	ans[u]=getans(R[u]-1)-before[u];
}
int main(){
	int e,rt=-1;
	scanf("%d",&e);
	for(int i=1;i<=e;i++){
		LL a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a!=-1)v[a].push_back({i,b,c});
		else rt=i;
		R[i]=b;T[i]=c;
	}
	dfs(rt,-1);
	for(int i=1;i<=e;i++)printf("%lld\n",ans[i]);
}


