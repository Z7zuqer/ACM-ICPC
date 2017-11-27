#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
int mp[maxn][maxn];
int n,t;
int vis[maxn],cek[maxn];
bool find(int u){
	for(int i=1;i<=n;i++){
		if(!vis[i]&&mp[u][i]){
			vis[i]=1;
			if(!cek[i]||find(cek[i])){
				cek[i]=u;
				return true;
			}
		}
	}
	return false;
}
bool work(){
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(!find(i))return false;
	}
	return true;
}
int main(){
	scanf("%d",&t);
	while(t--){
		memset(cek,0,sizeof(cek));
		memset(mp,0,sizeof(mp));
		
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&mp[i][j]);
			}
		}
		if(!work())cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}
