#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
struct node{
	int x,y;
}req[maxn];
int n,k,tot,ans,num[maxn*2],tr[maxn*8],flg[maxn*8];
int cmp(node m,node n){
	if(m.y==n.y)return m.x>n.x;
	return m.y<n.y;
}
void pre(){
	sort(num+1,num+1+tot);
	tot=unique(num+1,num+1+tot)-num-1;
	for(int i=1;i<=n;i++){
		req[i].x=lower_bound(num+1,num+tot+1,req[i].x)-num;
		req[i].y=lower_bound(num+1,num+tot+1,req[i].y)-num;
	}
}
void pushdown(int t){
	if(flg[t]){
		flg[t<<1|1]+=flg[t];
		flg[t<<1]+=flg[t];
		tr[t<<1]+=flg[t];
		tr[t<<1|1]+=flg[t];
		flg[t]=0;
	}
}
void pushup(int t){
	tr[t]=max(tr[t<<1],tr[t<<1|1]);
}
void update(int t,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		tr[t]++;flg[t]++;
		return ;
	}
	pushdown(t);
	int mid=(l+r)>>1;
	if(mid>=L)update(t<<1,l,mid,L,R);
	if(mid<R)update(t<<1|1,mid+1,r,L,R);
	pushup(t);
}
int query(int t,int l,int r,int L,int R){
	if(L<=l&&r<=R)return tr[t];
	int mid=(l+r)>>1,mx=0;
	pushdown(t);
	if(mid>=L)mx=max(mx,query(t<<1,l,mid,L,R));
	if(mid<R)mx=max(mx,query(t<<1|1,mid+1,r,L,R));
	pushup(t);
	return mx;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&req[i].x,&req[i].y);
		num[++tot]=req[i].x;
		num[++tot]=--req[i].y;
	}
	pre();
	sort(req+1,req+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(query(1,1,tot,req[i].x,req[i].y)<k){
			ans++;
			update(1,1,tot,req[i].x,req[i].y);
		}
	}
	cout<<ans<<endl;
}
