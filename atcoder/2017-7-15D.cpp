#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int n,sum[maxn],pre[maxn];
vector<int>v[maxn],mp;
void dfs(int u,int fa){
    sum[u]=1,pre[u]=fa;
    for(int i=0;i<v[u].size();i++)
    	if(v[u][i]!=fa){
        	dfs(v[u][i],u);
        	sum[u]+=sum[v[u][i]];
    	}
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
    	int a,b;
    	scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
    }
    dfs(1,0);
    for(int i=n;i;i=pre[i])mp.push_back(i);
    reverse(mp.begin(),mp.end());
    int r1=sum[mp[(mp.size()+1)/2]];
    int r2=n-r1;
    if(r1>r2) puts("Fennec");
    else puts("Snuke");
}



