#include<bits/stdc++.h>
using namespace std;
const int maxn= 50000;
int maxv[maxn<<2],minv[maxn<<2];
void build(int t,int l,int r){
	if(l==r){
		scanf("%d",&maxv[t]);
		minv[t]=maxv[t];
		return ;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	maxv[t]=max(maxv[t<<1],maxv[t<<1|1]);
	minv[t]=min(minv[t<<1],minv[t<<1|1]);
}
int query1(int t,int l,int r,int L,int R){
	if(l>=L&&r<=R)return maxv[t];
	int mid=(l+r)>>1,res=0;
	if(mid>=L)res=max(res,query1(t<<1,l,mid,L,R));
	if(mid<R)res=max(res,query1(t<<1|1,mid+1,r,L,R));
	return res;
}
int query2(int t,int l,int r,int L,int R){
	if(l>=L&&r<=R)return minv[t];
	int mid=(l+r)>>1,res=1e9;
	if(mid>=L)res=min(res,query2(t<<1,l,mid,L,R));
	if(mid<R)res=min(res,query2(t<<1|1,mid+1,r,L,R));
	return res;
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	build(1,1,n);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",query1(1,1,n,a,b)-query2(1,1,n,a,b));
	}
}
