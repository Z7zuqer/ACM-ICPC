#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int n,m,ans,vis[maxn][maxn];
char mp[maxn][maxn];
void bfs(int stax,int stay,int endx,int endy){
	
}
int main(){
	while(scanf("%d%d",&n,&m)==2){
		for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		ns=1e9;
		bfs(x1,y1,x2,y2);
		if(ans==1e9)puts("-1");
		else printf("%d\n",ans);
	}
}


