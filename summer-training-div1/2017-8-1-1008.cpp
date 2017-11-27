#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define LL long long
LL qpow(LL a,LL b){
	LL base=a,ans=1;
	while(b){
		if(b&1)ans=ans*base%mod;
		base=base*base%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	LL n,k;
	while(scanf("%lld%lld",&n,&k)!=EOF){
		LL r=qpow(n,k);
		LL div=sqrt(r);
		LL ans=0;
		for(int i=1;i<=div;i++){
			LL cnt1=r/(i*i);
			LL cnt2=r/((i+1)*(i+1));
			ans=(ans+(cnt1-cnt2)*i%mod)%mod;
		}
		printf("%lld\n",ans);
	}
}


