#include<bits/stdc++.h>
using namespace std;
char mp[53][53][53];
int h,l,w,vis[53][53][53],wel[53][53][53];
struct node{
	int x,y,z,step;
};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int bfs(int stax,int stay,int staz){
	queue<node>q;
	q.push({stax,stay,staz});
	vis[staz][stax][stay]=1;
	while(!q.empty()){
		int x=q.front().x,y=q.front().y,z=q.front().z;q.pop();
		if(mp[z][x][y]=='E')return 1;
		for(int i=0;i<4;i++){
			int tx=x+dx[i];
			int ty=y+dy[i];
			if(tx<1||ty<1||tx>l||ty>w)continue;
			if(!vis[z][tx][ty]&&mp[z][tx][ty]=='.'){
				vis[z][tx][ty]=1;
				q.push({tx,ty,z});
			}
			if(mp[z][tx][ty]=='E')return 1;
			if(mp[z][tx][ty]=='w'&&!vis[wel[z][tx][ty]][tx][ty]){
				vis[wel[z][tx][ty]][tx][ty]=1;
				q.push({tx,ty,wel[z][tx][ty]});
			}
			if(mp[z][tx][ty]=='s'){
				for(int k=z;k>=1;k--){
					if(mp[k][tx][ty]=='s'&&!vis[k][tx][ty]){
						vis[k][tx][ty]=1;
						q.push({tx,ty,k});
					}
					else break;
				}
				for(int k=z+1;k<=h;k++){
					if(mp[k][tx][ty]=='s'&&!vis[k][tx][ty]){
						vis[k][tx][ty]=1;
						q.push({tx,ty,k});
					}
					else break;
				}
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d%d%d",&l,&w,&h);
	int stax,stay,staz;
	for(int i=h;i>=1;i--)
		for(int j=1;j<=l;j++){
			scanf("%s",mp[i][j]+1);
			for(int k=1;k<=w;k++){
				if(mp[i][j][k]=='A')stax=j,stay=k,staz=i;
			}
		}
	memset(wel,-1,sizeof wel);
	for(int i=h;i>=1;i--)
		for(int j=1;j<=l;j++)
			for(int k=1;k<=w;k++)
				if(mp[i][j][k]=='w'&&wel[i][j][k]==-1){
					int minv=1e9;
					for(int u=i;u>=1;u--)
						if(mp[u][j][k]=='w')minv=min(minv,u);
						else break;
					for(int u=i;u>=1;u--)
						if(mp[u][j][k]=='w')wel[u][j][k]=minv;
						else break;
				}
	if(bfs(stax,stay,staz))puts("Yes");
	else puts("No");
}


