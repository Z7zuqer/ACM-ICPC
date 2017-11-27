#include<bits/stdc++.h>
using namespace std;
char mp[2100][2100];
int col[2100][2100],size[4000+7];
int n,m,vis[2100][2100],tmpcnt;
struct Node{int x,y;};
queue<Node> que;
bool row[2100],clm[2100];
void dfs(int x,int y,int k){
    que.push({x,y});
    vis[x][y] = 1;
    while(!que.empty()){
        tmpcnt++;
        //if(tmpcnt % 100000 == 0) printf("//%d\n",tmpcnt);
        int nx = que.front().x, ny = que.front().y; que.pop();
        col[nx][ny] = k;size[k]++;
        for(int i = nx + 1;i <= n;++i){
        	if(clm[ny]) break;
            if(!vis[i][ny] && mp[i][ny] == '+'){
                que.push({i,ny});
                vis[i][ny] = 1;
            }
        }
        for(int i = nx - 1;i >= 0;--i){
        	if(clm[ny]) break;
            if(!vis[i][ny] && mp[i][ny] == '+'){
                que.push({i,ny});
                vis[i][ny] = 1;
            }
        }
        for(int i = ny + 1;i <= m;++i){
        	if(row[nx]) break;
            if(!vis[nx][i] && mp[nx][i] == '+'){
                que.push({nx,i});
                vis[nx][i] = 1;
            }
        }
        for(int i = ny - 1;i >= 0;--i){
        	if(row[nx]) break;
            if(!vis[nx][i] && mp[nx][i] == '+'){
                que.push({nx,i});
                vis[nx][i] = 1;
            }
        }
        row[nx] = 1;
        clm[ny] = 1;
    }
}
int VIS[4000+7];
int main(){
	//freopen("C://Users//Duhao//Desktop//input.txt","r",stdin);
	scanf("%d%d",&n,&m);
	//n=2000;m=2000;
	for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!vis[i][j]&&mp[i][j]=='+')
				dfs(i,j,++cnt);
		}
	}
	int ans=0,ansL=-1,ansR=-1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='.'){
				int res=0;
				for(int k=1;k<=cnt;k++)VIS[i]=0;
				for(int k=1;k<=n;k++){
					if(VIS[col[k][j]]) break;
					if(mp[k][j]=='+'&&!VIS[col[k][j]]){
						res+=size[col[k][j]];
						VIS[col[k][j]]=1;
						break;
					}
				}
				for(int k=1;k<=m;k++){
					if(VIS[col[i][k]]) break;
					if(mp[i][k]=='+'&&!VIS[col[i][k]]){
						res+=size[col[i][k]];
						VIS[col[i][k]]=1;
						break;
					}
				}
				if(ans<res){
					ans=res;
					ansL=i;
					ansR=j;
				}
			}
		}
	if(ans==0)cout<<ans<<endl;
	else cout<<ans<<endl<<ansL<<" "<<ansR<<endl;
}

