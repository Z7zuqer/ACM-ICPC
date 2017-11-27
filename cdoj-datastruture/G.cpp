#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+107;
struct node{
	int lmx,rmx,mx,sum;
}tr[maxn<<2],x;
void pushup(int t){
	tr[t].sum=tr[t<<1].sum+tr[t<<1|1].sum;
	tr[t].mx=max(max(tr[t<<1].mx,tr[t<<1|1].mx),tr[t<<1].rmx+tr[t<<1|1].lmx);
	tr[t].lmx=max(tr[t<<1].lmx,tr[t<<1].sum+tr[t<<1|1].lmx);
	tr[t].rmx=max(tr[t<<1|1].rmx,tr[t<<1|1].sum+tr[t<<1].rmx);
} 
void build(int t,int l,int r){
	if(l==r){
		scanf("%d",&tr[t].sum);
		tr[t].mx=tr[t].lmx=tr[t].rmx=tr[t].sum;
		return ;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	pushup(t);
}
void update(int t,int l,int r,int pos,int v){
	if(l==r){
		tr[t].mx=tr[t].lmx=tr[t].rmx=tr[t].sum=v;
		return ;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)update(t<<1,l,mid,pos,v);
	else update(t<<1|1,mid+1,r,pos,v);
	pushup(t);
}
node query(int t,int l,int r,int L,int R){
	if(l>=L&&r<=R)return tr[t];
	int mid=(l+r)>>1,rr=0,r1=-1,r2=-1;node xx,x1,x2;
	if(mid>=L)x1=query(t<<1,l,mid,L,R),rr=1;
	if(mid<R)x2=query(t<<1|1,mid+1,r,L,R),rr+=3;
	if(rr==4){
		xx.sum=x1.sum+x2.sum;
		xx.lmx=max(x1.lmx,x1.sum+x2.lmx);
		xx.rmx=max(x2.rmx,x2.sum+x1.rmx);
		xx.mx=max(max(x1.mx,x2.mx),x1.rmx+x2.lmx);
		return xx;
	}
	else if(rr==1)return x1;
	else if(rr==3)return x2;
	else return xx;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	build(1,1,n);
	while(m--){
		int k,x,y;
		scanf("%d%d%d",&k,&x,&y);
		if(k==1)printf("%d\n",query(1,1,n,x,y).mx);
		if(k==2)update(1,1,n,x,y);
	}
}


