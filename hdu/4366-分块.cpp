#include<bits/stdc++.h>
using namespace std;
const int maxn=50010;
int magic,A[maxn],B[maxn],maxv[maxn],size[maxn];
pair<int,int>block[maxn];
int son[maxn],dfn[maxn],cnt;
vector<int>v[maxn];
void dfs(int u){
	dfn[u]=cnt++;
	for(int i=0;i<v[u].size();i++)
		dfs(v[u][i]);
	son[u]=cnt-1;
}
void update(int x,int siz){
	maxv[x]=block[x].second;
	for(int i=1;i<siz;i++)maxv[x-i]=max(maxv[x-i+1],block[x-i].second);
}
int find(int l,int r,int k){
	if(block[r].first<k)return -1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(block[mid].first>=k)r=mid;
		else l=mid;
	}
	return l;
}
int query(int x,int y,int k){
	int x_pos=x/magic,y_pos=y/magic,r=-1;
	if(x_pos==y_pos)
		if(block[y].first<k)return -1;
		else {
			while(x+1<y){
				int mid=(x+y)>>1;
				if(block[mid].first>=k)y=mid;
				else x=mid;
			}
			return maxv[x];
		}
	else{
		for(int i=x;i<=x_pos*magic+size[x_pos]-1;i++)if(block[i].first>=k){
			r=max(r,maxv[i]);
			break;
		}
		for(int i=x_pos+1;i<y_pos;i++){
			int u=find(x_pos*magic,x_pos*magic+size[x_pos],k);
			if(u!=-1)r=max(r,maxv[u]);
		}
		for(int i=y_pos*magic;i<=y;i++)if(block[i].first>=k){
			r=max(r,maxv[i]);
			break;
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;cnt=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<n;i++){
			int x;
			scanf("%d%d%d",&x,&A[i],&B[i]);
			v[x].push_back(i);
		}
		dfs(0);
		magic=sqrt(n);int sz=n/magic;		
		for(int i=0;i<=sz;i++)size[i]=min(magic,n-i*magic);
		for(int i=0;i<cnt;i++)block[dfn[i]]={B[i],A[i]};
		for(int i=0;i<=sz;i++)sort(block+i*magic,block+i*magic+size[i]);
		for(int i=0;i<=sz;i++)update(min(i*magic+magic-1,n-1),min(magic,n-i*magic));
		while(m--){
			int x;
			scanf("%d",&x);
			printf("%d\n",query(dfn[x],son[x],B[x]));
		}
	}
}


