#include<bits/stdc++.h>
using namespace std;
struct {
	int e,v,next;
}ed[1000001];
int head[100001],num,deg[100001],deg2[100001],dis[100001],n,maxv[100001],fa[100001];
vector<pair<int,int> >v[100001];
void add(int s,int e,int v){
	ed[num].e=e;ed[num].v=v;ed[num].next=head[s];head[s]=num++;
}
int work(){
	int r=0;
	queue<int>q;
	for(int i=1;i<=n;i++)if(!deg[i])q.push(i);
	while(!q.empty()){
		int k=q.front();q.pop();r++;
		for(int i=head[k];i!=-1;i=ed[i].next){
			if(--deg[ed[i].e]==0){
				q.push(ed[i].e);
				dis[ed[i].e]=dis[k]+ed[i].v;
			}
		}
	}
	return r==n;
}
int check(int k){
	if(k>=0&&k<=100)return 0;
	return 1;
}
void spfa(int sta){
	queue<int>q;
	q.push(sta);maxv[sta]=100;
	while(!q.empty()){
		int k=q.front();q.pop();
		for(int i=0;i<v[k].size();i++){
			int e=v[k][i].first,vv=v[k][i].second;
			if(maxv[e]==-1){
				maxv[e]=maxv[k]-vv;
				q.push(e);
			}
			else if(maxv[e]<maxv[k]-vv){
				maxv[e]=maxv[k]-vv;
				q.push(e);
			}
		}
	}
}
map<pair<int,int>,int>mp;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void uni(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)fa[min(fx,fy)]=max(fx,fy);
}
int main(){
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)head[i]=-1,fa[i]=i;num=0;
	memset(maxv,-1,sizeof(maxv));
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		mp[{x,y}]=max(z,mp[{x,y}]);
	}
	for(map<pair<int,int>,int>::iterator it=mp.begin();it!=mp.end();it++){
		int xx=((*it).first).first,yy=(*it).first.second,z=(*it).second;
		int x=find(xx),y=find(yy);
		if(!z)uni(x,y);
		else {
			deg[x]++;deg2[y]++;add(y,x,z);v[x].push_back({y,z});	
		}
	}
	for(int i=1;i<=n;i++)fa[i]=find(i);
	if(!work())return 0*printf("-1\n");
	for(int i=1;i<=n;i++)
		if(check(dis[fa[i]]))return 0*printf("-1\n");
	for(int i=1;i<=n;i++)
		if(deg2[fa[i]]==0)spfa(fa[i]);
	for(int i=1;i<=n;i++)
		if(check(maxv[fa[i]]))return 0*printf("-1\n");
	for(int i=1;i<=n;i++)printf("%d %d\n",dis[fa[i]],maxv[fa[i]]);
}


