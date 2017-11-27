#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int tr[maxn][maxn<<2],lazy[maxn][maxn<<2];
void pushup(int t,int x){
	tr[x][t]=tr[x][t<<1]+tr[x][t<<1|1];
}
void pushdown(int t,int x){
	if(lazy[x][t]){
		lazy[x][t<<1]+=lazy[x][t];
		lazy[x][t<<1|1]+=lazy[x][t];
		tr[x][t<<1]+=lazy[x][t];
		tr[x][t<<1|1]+=lazy[x][t];
		lazy[x][t]=0;
	}
}
int query(int pos,int l,int r,int t,int x){
	if(l==r&&l==pos)return tr[x][t];
	int mid=(l+r)>>1;
	pushdown(t,x);
	if(mid>=pos)return query(pos,l,mid,t<<1,x);
	else return query(pos,mid+1,r,t<<1|1,x);
	pushup(t,x);
}
void update(int L,int R,int l,int r,int t,int x){
	//cout<<l<<" "<<r<<endl;
	if(l>=L&&r<=R){
		tr[x][t]++;
		lazy[x][t]++;
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(t,x);
	if(R<=mid)update(L,R,l,mid,t<<1,x);
	else if(L>mid)update(L,R,mid+1,r,t<<1|1,x);
	else {
		update(L,R,l,mid,t<<1,x);
		update(L,R,mid+1,r,t<<1|1,x);
	}
	pushup(t,x);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,q;
		char s[2];
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)memset(tr[i],0,sizeof(tr[i]));//,memset(lazy[i],0,sizeof(lazy[i]));
		while(q--){
			scanf("%s",s);
			if(s[0]=='C'){
				int x1,x2,y1,y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				for(int i=x1;i<=x2;i++)update(y1,y2,1,n,1,i);
			}
			if(s[0]=='Q'){
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%d\n",query(y,1,n,1,x));
			}
		}
	} 
}
