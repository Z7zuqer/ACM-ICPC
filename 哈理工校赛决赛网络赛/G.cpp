#include<bits/stdc++.h>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char mp[610][610];
int vis[610][610],n,m;
int bfs(int sx,int sy){
	queue<pair<int,int> >q;
	vis[sx][sy]=1;
	q.push({sx,sy});
	while(!q.empty()){
		int nowx=q.front().first,nowy=q.front().second;q.pop();
		for(int i=0;i<4;i++){
			int tx=nowx+dx[i];
			int ty=nowy+dy[i];
			if(tx>=1&&ty>=1&&tx<=n&&ty<=m&&!vis[tx][ty]&&mp[tx][ty]!='#'){
				vis[tx][ty]=1;
				if(mp[tx][ty]=='E')return 1;
				q.push({tx,ty});
			}
		}
	}
	return 0;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		int sx,sy,ex,ey;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			scanf("%s",mp[i]+1);
			for(int j=1;j<=m;j++){
				if(mp[i][j]=='S')sx=i,sy=j;
				if(mp[i][j]=='E')ex=i,ey=j;
			}
		}
		int flg=bfs(sx,sy);
		if(flg)puts("Yes");
		else puts("No");
	}
}


