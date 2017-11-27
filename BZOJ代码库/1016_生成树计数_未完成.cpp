#include<bits/stdc++.h>
using namespace std;
const int mod=31011;
const int maxn=105;
int n,m;
int dep[maxn],fa[x],vis[maxn];
int res[maxn][maxn],mp[maxn][maxn];
struct node{
	int s,e,v;
}ed[maxn*10];
bool cmp(node m,node n){
	return m.v<n.v;
}
int find(int x){
	if(x==fa[x])return fa[x];
	return find(fa[x]);
}
int kinff(){
	
}
int main(){ 
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++){
		fa[i]=i;
		vis[i]=0;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%%d",&res[i].s,&res[i].e,&res[i].v);
		dep[res[i].s]++;dep[res[i].e]++;
		mp[res[i].s][res[i].e]=mp[res[i].e][res[i].s]=1;
	}
	sort(res,res+m,cmp);
	int edlen=-1;
	for(int i=0;i<m;i++){
		
	}
	
}
 
