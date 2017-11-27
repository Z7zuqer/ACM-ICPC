#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
vector<int>v[maxn*2];
int n,m,mark[maxn*2],sta[maxn*2],top;
int dfs(int u){
	if(mark[u])return 1;
	if(mark[u^1])return 0;
	sta[top++]=u;
	mark[u]=1;
	for(int i=0;i<v[u].size();i++)if(!dfs(v[u][i]))return 0;
	return 1;
}
int work(){
	memset(mark,0,sizeof mark);
	for(int i=0;i<2*n;i+=2){
		if(!mark[i]&&!mark[i^1]){
			top=0;
			if(!dfs(i)){
				while(top>0)mark[sta[--top]]=0;
				if(!dfs(i^1))return 0;
			}
		}
	}
	return 1;
}
void add(int s,int sv,int e,int ev){
	int x=s*2+sv;
	int y=e*2+ev; 
	v[x].push_back(y^1);
	v[y].push_back(x^1);
}
int ord[maxn];
int main(){
	while(scanf("%d%d",&n,&m)!=EOF&&n&&m){
		for(int i=0;i<n*2;i++)v[i].clear();
		double sum=0;
		for(int i=1;i<=n;i++)scanf("%d",&ord[i]),sum+=ord[i];
		double div=sum/n;
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			if(ord[x]<div&&ord[y]<div)add(x-1,0,y-1,0);
			if(ord[x]>=div&&ord[y]>=div)add(x-1,0,y-1,0);
			add(x-1,1,y-1,1);
		}
		if(work()){
			for(int i=0;i<2*n;i+=2){
				//printf("%d ",i/2+1);
				if(mark[i]){
					if(ord[i/2+1]>=div)puts("A");
					else puts("B");
				}
				else puts("C");
			}
		}
		else puts("No solution.");
	}
}


