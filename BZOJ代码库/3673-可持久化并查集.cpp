#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e4+7;
struct {
	int l,r,fa;
}tr[maxn*50];
int n,m,tot,rt[maxn];
void update(int &x,int l,int r,int loca,int v){
	tr[++tot]=tr[x];x=tot;
	if(l==r){
		tr[x].fa=v;
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=loca)update(tr[x].l,l,mid,loca,v);
	else update(tr[x].r,mid+1,r,loca,v);
}
int query(int now,int l,int r,int x){
	if(l==r)return tr[now].fa;
	int mid=(l+r)>>1;
	if(mid>=x)return query(tr[now].l,l,mid,x);
	else return query(tr[now].r,mid+1,r,x);
}
int find(int x,int k){
	int fa=query(rt[k],0,n,x);
	//cout<<x<<" "<<fa<<endl;
	if(fa==x)return x;
	int t=find(fa,k);
	//update(rt[k],0,n,x,t);
	return t;
}
void uni(int x,int y,int k){
	int fx=find(x,k);
	int fy=find(y,k);
	if(fx!=fy){
		if(rand()&1)update(rt[k],0,n,fy,fx);
		else update(rt[k],0,n,fx,fy);
	}
}
int main(){
	while(scanf("%d%d",&n,&m)==2){
		int now=0;tot=0;
		memset(rt,0,sizeof(rt));
		for(int i=1;i<=n;i++)update(rt[now],0,n,i,i);
		for(int i=1;i<=m;i++){
			int k;
			scanf("%d",&k);
			rt[i]=rt[i-1];
			if(k==1){
				int a,b;
				scanf("%d%d",&a,&b);
				uni(a,b,i);
			}
			if(k==2){
				int a;
				scanf("%d",&a);
				rt[i]=rt[a];
			}
			if(k==3){
				int a,b;
				scanf("%d%d",&a,&b);
				int fa=find(a,i);
				int fb=find(b,i);
				printf("%d\n",fa==fb);
			}
		}
	}
}


