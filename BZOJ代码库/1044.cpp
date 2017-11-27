#include<bits/stdc++.h>
using namespace std;
const int maxn=50050;
const int mod=10007;
int n,m;
int seq[maxn],maxm,sum[maxn];
bool check(int k){
	if(k<maxm)return false;
	int re=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(seq[i]>k)return false;
		if(re+seq[i]<=k)re+=seq[i];
		else {
			re=seq[i],cnt++;
			if(cnt>m)return false;
		}
	}
	if(cnt<=m)return true;
	return false;
}
int dp[maxn][2];
int main(){
	int l=1,r=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&seq[i]);
		sum[i]=sum[i-1]+seq[i];
		r+=seq[i];
		maxm=max(maxm,seq[i]);
	}
	int mid;//,res;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid))r=mid;//-1,res=mid;
		else l=mid+1;
	}
	//r=r+1;
	//cout<<l<<" "<<r<<" "<<mid<<" "<<res<<endl; 
	int now=1;
	int ans=0;
	for(int i=1;i<=n;i++)
		if(sum[i]<=r)dp[i][0]=1;
	//ans+=dp[n][0]; 
	for(int i=1;i<=m;i++){
		int sumf=0;
		int mink=1;
		for(int j=1;j<=n;j++){
			while(mink<j&&sum[j]-sum[mink]>r){
				sumf=((sumf-dp[mink][!now])+mod)%mod;
				++mink;
			}
			dp[j][now]=sumf;
			sumf+=dp[j][!now];
			sumf%=mod;
		} 
		//cout<<sumf<<endl;
		ans=(ans+dp[n][now])%mod;
		now=!now;
	}
	cout<<r<<" "<<ans<<endl;
}
