#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
int ans=0,now=0;
int tr[maxn<<2],cnt[maxn<<2],A[maxn];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
void build(int t,int l,int r){
	if(l==r){
		tr[t]=A[l];
		cnt[t]=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	tr[t]=gcd(tr[t<<1],tr[t<<1|1]);
	if(tr[t]==tr[t<<1])cnt[t]+=cnt[t<<1];
	if(tr[t]==tr[t<<1|1])cnt[t]+=cnt[t<<1|1];
}
int query(int t,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		if(now==0){
			now=tr[t];
			ans=cnt[t];
			return now;
		}
		else {
			int tmp=gcd(now,tr[t]);
			if(tmp!=now){
				now=tmp;
				if(tmp==tr[t])ans=cnt[t];		
				else ans=0;
			}
			else {
				if(tmp==tr[t])ans+=cnt[t];
			}
			return tr[t];
		}
	}
	int mid=(l+r)>>1,res=0;
	if(mid>=L)res=query(t<<1,l,mid,L,R);
	if(mid<R){
		if(res==0)res=query(t<<1|1,mid+1,r,L,R);
		else res=gcd(res,query(t<<1|1,mid+1,r,L,R));
	}
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	build(1,1,n);
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		ans=0;now=0;
		query(1,1,n,l,r);
		printf("%d\n",r-l+1-ans);
	}
}


