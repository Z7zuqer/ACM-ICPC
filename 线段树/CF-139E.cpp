#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
int n,m;
double tr[maxn*15],flg[maxn*15]; 
struct {
	int a,h;
	double l,r;
}req[maxn];
struct {
	int b,z;
}rem[maxn];
int A[maxn*5];
void build(int t,int l,int r){
	flg[t]=tr[t]=1;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
}
void pushdown(int t){
	if(fabs(flg[t]-1)>1e-5){
		flg[t<<1]*=flg[t];
		flg[t<<1|1]*=flg[t];
		tr[t<<1]*=flg[t];
		tr[t<<1|1]*=flg[t];
		flg[t]=1;
	}
}
void update(int t,int l,int r,int L,int R,double v){
	//cout<<v<<endl;
	if(L<=l&&r<=R){
		flg[t]*=v;
		tr[t]*=v;
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(t);
	if(mid>=L)update(t<<1,l,mid,L,R,v);
	if(mid<R)update(t<<1|1,mid+1,r,L,R,v);
}
double query(int t,int l,int r,int pos){
	if(l==r)return tr[t];
	int mid=(l+r)>>1;
	pushdown(t);
	if(mid>=pos)return query(t<<1,l,mid,pos);
	return query(t<<1|1,mid+1,r,pos);
}
int main(){
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%lf%lf",&req[i].a,&req[i].h,&req[i].l,&req[i].r);
		A[++cnt]=req[i].a-1;
		A[++cnt]=req[i].a+1;
		A[++cnt]=req[i].a-req[i].h;
		A[++cnt]=req[i].a+req[i].h;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&rem[i].b,&rem[i].z);
		A[++cnt]=rem[i].b;
	}
	sort(A+1,A+1+cnt);
	cnt=unique(A+1,A+1+cnt)-A-1;
	build(1,1,cnt);
	for(int i=1;i<=n;i++){
		int staL=upper_bound(A+1,A+1+cnt,req[i].a-req[i].h)-A-1;
		int endL=upper_bound(A+1,A+1+cnt,req[i].a-1)-A-1;
		int staR=upper_bound(A+1,A+1+cnt,req[i].a+1)-A-1;
		int endR=upper_bound(A+1,A+1+cnt,req[i].a+req[i].h)-A-1;
		//cout<<staL<<" "<<endL<<" "<<staR<<" "<<endR<<endl;
		update(1,1,cnt,staL,endL,1-req[i].l/100.0);
		update(1,1,cnt,staR,endR,1-req[i].r/100.0);
	}
	/*
	1 1
	3 2 73 12
	1 5
	*/
	double ans=0;
	for(int i=1;i<=m;i++)ans+=1.0*rem[i].z*(query(1,1,cnt,upper_bound(A+1,A+1+cnt,rem[i].b)-A-1));
	printf("%.5lf\n",ans);
}


