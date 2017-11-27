#include<bits/stdc++.h>
using namespace std;
const int maxn=200050;
struct {
	int l,r,maxm;
}a[maxn<<2];
void puhup(int t){
	a[t].maxm=max(a[t<<1].maxm,a[t<<1|1].maxm);
}
void build(int t,int l,int r){
	a[t].l=l;a[t].r=r;
	if(l==r){
		scanf("%d",&a[t].maxm);
		return ;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r); 
}
int query(int t,int l,int r){
	
}
void update(int t,int l,int r,in)
