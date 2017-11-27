#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+7;
int tr[maxn<<2];
struct{
	int k,x,y;
}req[maxn];
set<int>s[maxn];
void build(int t,int l,int r){
	tr[t]=-1;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
}
void update(int t,int l,int r,int pos){
	if(l==r){
		if(s[pos].size())tr[t]=*(--s[pos].end());
		else tr[t]=-1;
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=pos)update(t<<1,l,mid,pos);
	if(mid<pos)update(t<<1|1,mid+1,r,pos);
	tr[t]=max(tr[t<<1],tr[t<<1|1]);
}
int query(int t,int l,int r,int x,int y){
	if(r<=x)return -1;
	if(tr[t]<=y)return -1;
	if(l==r)return l;
	int mid=(l+r)>>1;
	int res=query(t<<1,l,mid,x,y);
	if(res==-1)res=query(t<<1|1,mid+1,r,x,y);
	return res;
}
int A[maxn];w
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char ss[10];
		scanf("%s%d%d",ss,&req[i].x,&req[i].y);
		if(ss[0]=='a')req[i].k=1;
		if(ss[0]=='r')req[i].k=2;
		if(ss[0]=='f')req[i].k=3;
		A[i]=req[i].x;
	}
	sort(A+1,A+1+n);
	int cnt=unique(A+1,A+1+n)-A-1;
	build(1,1,cnt);
	for(int i=1;i<=n;i++){
		int x=upper_bound(A+1,A+1+cnt,req[i].x)-A-1;
		int y=req[i].y;
		if(req[i].k==1){
			s[x].insert(y);
			update(1,1,cnt,x);
		}
		if(req[i].k==2){
			s[x].erase(y);
			update(1,1,cnt,x);
		}
		if(req[i].k==3){
			int res=query(1,1,cnt,x,y);
			if(res==-1)puts("-1");
			else printf("%d %d\n",A[res],*s[res].lower_bound(y+1));
		}
	}
}


