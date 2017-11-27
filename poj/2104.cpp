#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=1000000+7;
struct {
	int l,r,cnt;
}tr[maxn*30];
int tot=1,rt[maxn],A[maxn];
void insert(int &x,int l,int r,int v){
	tr[tot++]=tr[x];x=tot-1;++tr[x].cnt;
	if(l==r)return ;
	int mid=(l+r)>>1;
	if(v<=mid)insert(tr[x].l,l,mid,v);
	else insert(tr[x].r,mid+1,r,v);
}
int query(int pre,int now,int l,int r,int k){
	if(l==r)return l;
	int re=tr[tr[now].l].cnt-tr[tr[pre].l].cnt;
	int mid=(l+r)>>1;
	if(k<=re)return query(tr[pre].l,tr[now].l,l,mid,k);
	else return query(tr[pre].r,tr[now].r,mid+1,r,k-re);
}
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=n;i++)insert(rt[i]=rt[i-1],1,n,A[i]);
	scanf("%d",&m);
	while(m--){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",query(rt[l-1],rt[r],1,n,k));
	}
}


