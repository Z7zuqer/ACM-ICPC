#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
vector<int>v[maxn]; 
int A[maxn],B[maxn],ans;
vector<int>vv;
void dfs(int u,int pre,int flg1,int flg2,int dist){
	// flg1 jishu flg2 oushu
	int flg_now=0;
	if(dist%2==0){
		if(flg2)A[u]^=1;
		if(A[u]!=B[u]){
			vv.push_back(u);
			flg_now=1;
		}
	}
	else {
		if(flg1)A[u]^=1;
		if(A[u]!=B[u]){
			vv.push_back(u);
			flg_now=1;
		}	
	}
	/*
5
1 3
1 2
2 4
3 5
0 0 1 1 1
1 0 0 1 1
	*/
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(e==pre)continue;
		if((dist+1)&1)dfs(e,u,flg1,(flg_now+flg2)%2,dist+1);
		else dfs(e,u,(flg1+flg_now)%2,flg2,dist+1);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=n;i++)scanf("%d",&B[i]);
	dfs(1,0,0,0,0);
	printf("%d\n",vv.size());
	for(int i=0;i<vv.size();i++)printf("%d\n",vv[i]);
}


