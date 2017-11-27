#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
struct {
	int e,next;
}ed[200010];
int head[maxn],num;
int wh[maxn];
void add(int s,int e){
	ed[num].e=e;ed[num].next=head[s];head[s]=num++;
}
int n,m,k;
int pos[maxn],siz[maxn],vis[maxn],bsiz[maxn];
void dfs(int u,int pre,int cnt){
	if(wh[u])vis[cnt]=1;
	pos[u]=cnt;siz[cnt]++;
	for(int i=head[u];i!=-1;i=ed[i].next){
		bsiz[cnt]++;	
		if(ed[i].e!=pre&&!pos[ed[i].e]){
			dfs(ed[i].e,u,cnt);
		}
	}
}
int main(){
	memset(head,-1,sizeof(head));
	scanf("%d%d%d",&n,&m,&k);
	int a,b;
	for(int i=0;i<k;i++){
		scanf("%d",&a);
		wh[a]=1;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
	}
	int cnt=1,maxm=0;
	long long ans=0,r=0,r2=0,cntb=0;
	for(int i=1;i<=n;i++){
		if(!pos[i]){
			dfs(i,-1,cnt);
			if(!vis[cnt]){
				cntb+=bsiz[cnt]/2;
				r2+=siz[cnt];
			}
			else {
				maxm=max(maxm,siz[cnt]);
				r+=siz[cnt]*(siz[cnt]-1)/2-bsiz[cnt]/2;
				//cout<<bsiz[cnt]<<endl;
			}
			cnt++;
		}
	}
	long long req=r2*maxm;
	cout<<req+r2*(r2-1)/2-cntb+r<<endl;
}
