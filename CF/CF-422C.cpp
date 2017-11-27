#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct node{
	LL x,mask,v,cost;
}r[400100];
int cmp(node m,node n){
	if(m.x==n.x)return m.mask>n.mask;
	return m.x<n.x;
}
LL dp[200100];
int main(){
	int n,k,tot=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		LL a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		r[++tot]={a,0,b-a+1,c};
		r[++tot]={b,1,b-a+1,c};
	}
	sort(r+1,r+tot,cmp);
	for(int i=0;i<=200099;i++)dp[i]=3e9;
	LL ans=3e9,flg=0;
	for(int i=1;i<=tot;i++){
		if(r[i].mask)dp[r[i].v]=min(dp[r[i].v],r[i].cost);
		else 
			if(k>r[i].v)
				if(dp[k-r[i].v]!=3e9) 
					ans=min(ans,1LL*dp[k-r[i].v]+r[i].cost);
			//,cout<<r[i].v<<" "<<r[i].cost<<endl;;
	}
	if(ans!=3e9)cout<<ans<<endl;
	else cout<<-1<<endl;
}


