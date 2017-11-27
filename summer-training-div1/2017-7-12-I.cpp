#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+7;
int n,m;
struct {
	int e,next,v,idx;
}ed[maxn<<1],ed_now[maxn<<1];
int num,head[100100],vis[100100],d[100100],dis[100100];
void add(int s,int e,int v){
	ed[num].e=e;ed[num].next=head[s];ed[num].v=v;head[s]=num++;
}
void spfa_end(){
	vis[n]=1;
	queue<int>q;
	q.push(n);
	d[n]=0;
	while(!q.empty()){
		int k=q.front();q.pop();vis[k]=0;
		for(int i=head[k];i!=-1;i=ed[i].next){
			int e=ed[i].e;
			if(d[k]+1<d[e]){
				d[e]=d[k]+1;
				if(!vis[e]){
					vis[e]=1;
					q.push(e);
				}
			}
		}
	}
}
int ans[100100];
vector<int>v[100100];
void bfs(){
	memset(vis,0,sizeof(vis));
    v[d[1]].push_back(1);
    for(int i=d[1];i>0;i--){
    	for(int j=0;j<v[i].size();j++){
    		int k=v[i][j];
    		if(vis[k])continue;
    		vis[k]=1;
    		for(int u=head[k];u!=-1;u=ed[u].next){
    			//cout<<k<<" "<<ed[u].e<<endl;
    			//if(ed[u].e==4)
    				//cout<<d[ed[u].e]+i<<" "<<d[1]<<endl;
				if(d[ed[u].e]==i-1){
					//cout<<k<<" "<<ed[u].e<<endl;
    				if(ed[u].v<ans[i]){
    					ans[i]=ed[u].v;
    					v[i-1].clear();
    					v[i-1].push_back(ed[u].e);
    				}	
    				else if(ed[u].v==ans[i])v[i-1].push_back(ed[u].e);
    			}
    		}
    	}
    }
    printf("%d\n",d[1]);
    for(int i=d[1];i>0;i--)printf("%d ",ans[i]);
    cout<<endl;
}
int main(){
	//freopen("ideal.in ","r",stdin);
	//freopen("ideal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)head[i]=-1,ans[i]=dis[i]=d[i]=1e9+1;
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	spfa_end();
	//for(int i=1;i<=4;i++)cout<<d[i]<<" ";cout<<endl;
	bfs();
}
