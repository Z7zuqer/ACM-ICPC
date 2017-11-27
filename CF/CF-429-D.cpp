#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+7;
vector<pair<int,int> >v[maxn];
int col[maxn],deg[maxn],insta[maxn];
vector<int>ans;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&col[i]);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back({b,i});
		v[b].push_back({a,i});
		if(col[b]!=-1)deg[a]++;
		if(col[a]!=-1)deg[b]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(col[i]!=-1&&(deg[i]%2)!=col[i]){
			q.push(i);
			insta[i]=1;
		}
	}
	while(!q.empty()){
		int k=q.front();q.pop();insta[k]=0;
		if(deg[k]%2==col[k])continue;
		int flg=-1;
		for(int i=0;i<v[k].size();i++){
			int e=v[k][i];
			if(insta[e]==1){
				
			}
		}
	}
}


