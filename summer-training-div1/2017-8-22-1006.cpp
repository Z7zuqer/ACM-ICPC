#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=100100;
vector<pair<int,LL> >v[maxn][2];
LL minv,dis[maxn][2][2];
int col[maxn][2][2];
priority_queue<pair<LL,int> >q[2];
void dij(int flg){
	while(!q[flg].empty()){
		//for(;!q[flg].empty()&&-dis[q[flg].top().second][flg]!=q[flg].top().first;q[flg].pop());
		if(q[flg].empty())break;
		int k=q[flg].top().second;q[flg].pop();
		for(int i=0;i<v[k][flg].size();i++){
			int e=v[k][flg][i].first;
			LL va=v[k][flg][i].second;
			if(dis[e][flg][0]>dis[k][flg][0]+va){
				dis[e][flg][1]=dis[e][flg][0]+va;
				col[e][flg][1]=col[k][flg][0];
				
				dis[e][flg][0]=dis[k][flg][0]+va;
				col[e][flg][0]=col[k][flg][0];
				q[flg].push({-dis[e][flg][0],e});
			}
			else if(dis[e][flg][1]>dis[k][flg][0]+va){
				dis[e][flg][1]=dis[k][flg][0]+va;
				col[e][flg][1]=col[k][flg][1];
				q[flg].push({-dis[e][flg][1],e});
			}
		}
	}
}
int main(){
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)col[i][0][0]=col[i][0][1]=col[i][1][0]=col[i][1][1]==0;
		for(int i=1;i<=n;i++)v[i][0].clear();
		for(int i=1;i<=n;i++)v[i][1].clear();
		for(int i=1;i<=m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			v[a][0].push_back({b,c});
			v[b][1].push_back({a,c});
		}
		int kkk;
		while(!q[1].empty())q[1].pop();
		while(!q[0].empty())q[0].pop();
		minv=1e18;
		for(int i=1;i<=n;i++)for(int j=0;j<=1;j++)dis[i][j][0]=dis[i][j][1]=1e18;
		scanf("%d",&kkk);
		int cnt=1;
		for(int i=1;i<=kkk;i++){
			int x;
			scanf("%d",&x);
			q[0].push({0,x});
			q[1].push({0,x});
			dis[x][0][0]=dis[x][0][1]=dis[x][1][0]=dis[x][1][1]=0;
			col[x][0][0]=col[x][0][1]=col[x][1][0]=col[x][1][1]=cnt++;
		}
		dij(0);
		dij(1);
		for(int i=1;i<=n;i++)
			for(int j=0;j<=1;j++)
				for(int k=0;k<=1;k++)
					for(int jj=0;jj<=1;jj++)
						for(int kk=0;kk<=1;kk++)
							if(col[i][j][k]!=col[i][jj][kk])
								minv=min(minv,dis[i][j][k]+dis[i][jj][kk]);
		printf("Case #%d: %lld\n",cas++,minv);
	}
}


