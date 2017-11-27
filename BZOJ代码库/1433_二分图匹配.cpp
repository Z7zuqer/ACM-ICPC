#include<bits/stdc++.h>
using namespace std;
int mp[51][51];
int cek[51],vis[51];
int wh[51],is[51];
int n;  
bool dfs(int u){
//	vis[u]=1;
	for(int i=1;i<=n;i++){
		if(!vis[i]&&mp[u][i]){
			vis[i]=1;
			if(!cek[i]||dfs(cek[i])){
				cek[i]=u;
				return 1;
			}
		}
	}
	return 0;
} 
int getans(){
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i))ans++;
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int cnt=0;
		scanf("%d",&n);
		memset(cek,0,sizeof(cek));
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=n;i++)scanf("%d",&is[i]);//是否在校学生 
		for(int i=1;i<=n;i++)scanf("%d",&wh[i]);//是否回家
		for(int i=1;i<=n;i++)
			if(!is[i]||(is[i]&&!wh[i]))
				cnt++;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				int x;
				scanf("%d",&x);
				if(x&&is[j]&&((is[i]&&!wh[i])||!is[i]))mp[i][j]=1;
				if(is[i]&&!wh[i])mp[i][i]=1;
			}
		if(getans()==cnt)cout<<"^_^"<<endl;
		else cout<<"T_T"<<endl;
	}
}
