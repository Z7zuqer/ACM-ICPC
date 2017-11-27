#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=200100;
LL minv[maxn<<1],lazy[maxn<<1];
struct node{
	char c;
	int hh,mm,dd,MM,cost;
	int pos,ori;
}r[maxn];
int cmp1(node m,node n){
	if(m.MM==n.MM){
		if(m.dd==n.dd){
			if(m.hh==n.hh)return m.mm<n.mm;
			return m.hh<n.hh;
		}
		return m.dd<n.dd;
	}
	return m.MM<n.MM;
}
int cmp2(node m,node n){
	return m.ori<n.ori;
}
void pushup(int t){
	minv[t]=min(minv[t<<1],minv[t<<1|1]);
}
void pushdown(int t){
	if(lazy[t]){
		lazy[t<<1]+=lazy[t];
		lazy[t<<1|1]+=lazy[t];
		minv[t<<1]+=lazy[t];
		minv[t<<1|1]+=lazy[t];
		lazy[t]=0;
	}
}
void update(int t,int l,int r,int L,int R,LL v){
	if(L<=l&&r<=R){
		minv[t]+=v;
		lazy[t]+=v;
		return ;
	}
	pushdown(t);
	int mid=(l+r)>>1;
	if(L<=mid)update(t<<1,l,mid,L,R,v);
	if(R>mid)update(t<<1|1,mid+1,r,L,R,v);
	pushup(t);
}
int main(){
	char c;
	int n,dd,MM,hh,mm,cost;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("\n%c%d%d%*c%d%d%*c%d",&r[i].c,&r[i].cost,&r[i].dd,&r[i].MM,&r[i].hh,&r[i].mm);
		r[i].ori=i;
		//cout<<r[i].c<<" "<<r[i].cost<<" "<<r[i].dd<<" "<<r[i].MM<<" "<<r[i].hh<<" "<<r[i].mm<<endl;//<<" "<<<<" "<<
	}
	sort(r+1,r+1+n,cmp1);
	for(int i=1;i<=n;i++)r[i].pos=i;
	sort(r+1,r+1+n,cmp2);
	for(int i=1;i<=n;i++){
		update(1,1,n,r[i].pos,n,r[i].cost*((r[i].c=='+')?1:-1));
		printf("%I64d\n",minv[1]>=0?0:minv[1]);
	}
}


