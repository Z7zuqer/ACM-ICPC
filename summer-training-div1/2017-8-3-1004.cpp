#include<bits/stdc++.h>
using namespace std;
const int maxn=60010;
int ansL,A[maxn],n,LAST[maxn],flg[maxn<<2];
double ansM,tr[maxn<<2];
void build(int t,int l,int r,double k){
	int mid=(l+r)>>1;
	tr[t]=k*l;flg[t]=0;
	if(l==r)return ;
	build(t<<1,l,mid,k);
	build(t<<1|1,mid+1,r,k);
	tr[t]=min(tr[t<<1],tr[t<<1|1]);
}
void pushdown(int t){
	if(flg[t]){
		tr[t<<1]+=flg[t];
		tr[t<<1|1]+=flg[t];
		flg[t<<1]+=flg[t];
		flg[t<<1|1]+=flg[t];
		flg[t]=0;
	}
}
void update(int t,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		tr[t]+=1;flg[t]+=1;
		return ;
	}
	pushdown(t);
	int mid=(l+r)>>1;
	if(mid>=L)update(t<<1,l,mid,L,R);
	if(mid<R)update(t<<1|1,mid+1,r,L,R);
	tr[t]=min(tr[t<<1],tr[t<<1|1]);
}
double query(int t,int l,int r,int L,int R){
	if(L<=l&&r<=R)return tr[t];
	int mid=(l+r)>>1;
	double res=1e9;
	pushdown(t);
	if(mid>=L)res=min(res,query(t<<1,l,mid,L,R));
	if(mid<R)res=min(res,query(t<<1|1,mid+1,r,L,R));
	tr[t]=min(tr[t<<1],tr[t<<1|1]);
	return res;
}
int check(double k){
	build(1,1,n,k);
	for(int i=1;i<=n;i++)LAST[i]=0;
	for(int r=1;r<=n;r++){
		ansL=-1;ansM=1e9;
		update(1,1,n,LAST[A[r]]+1,r);
		if(query(1,1,n,1,r)<=k*(r+1))return 1;
		LAST[A[r]]=r;
	}
	return 0;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		double l=0,r=1;
		for(int times=0;times<=30;times++){
			double mid=(l+r)/2;
			if(check(mid))r=mid;
			else l=mid;
		}
		printf("%.10lf\n",l);
	}
}


