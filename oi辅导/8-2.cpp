#include<bits/stdc++.h>
using namespace std;
char mp[11][11];
int n,m,col[11][11];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
void bfs(int x,int y){
	queue<pair<int,int> >q;
	q.push({x,y});
	while(!q.empty()){
		int kx=q.front().first,ky=q.front().second;q.pop();
		for(int i=0;i<4;i++){
			int tx=kx+dx[i];
			int ty=ky+dy[i];
			if(col[tx][ty]==-1&&tx>=1&&ty>=1&&tx<=n&&ty<=m&&mp[tx][ty]==mp[x][y]){
				col[tx][ty]=1;
				q.push({tx,ty});
			}
		}
	}
} 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
	memset(col,-1,sizeof col);
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(col[i][j]==-1){
				cnt++;
				
				bfs(i,j);
			}
k	cout<<cnt<<endl;
}
00





