#include<bits/stdc++.h>
using namespace std;
int flg=1,dep[100100],A[100100];
stack<int>s;
int vis[100100];
vector<int>v[100100];
void dfs(int u,int pre){
	if(!flg)return ;
	if(!vis[A[u]])s.push(A[u]),vis[A[u]]=1;
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(!flg)return ;
		if(A[e]!=e&&A[e]!=A[u]){
			flg=0;
			return ;
		}
		dfs(e,u);
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		dep[y]++;
	}
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=n;i++){
		if(!dep[i]){
			if(A[i]!=i)return 0*printf("-1\n");
			dfs(i,-1);
			if(!flg)return 0*printf("-1\n");
		}
	}
	cout<<s.size()<<endl;
	while(s.size())printf("%d\n",s.top()),s.pop();
}


