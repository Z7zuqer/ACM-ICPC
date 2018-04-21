#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL qpow(LL base,LL n,int k){
	if(n<=0)return 1;
	LL res=1;
	while(n){
		if(n&1)res=base*res%k;
		n>>=1;
		base=base*base%k;
	}
	return res;
}
LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		LL l,r;
		int k;
		scanf("%lld%lld%d",&l,&r,&k);
		if(k==1){
			printf("Case #%d: 0\n",cas++);
			continue;
		}
		if(r-l+1<=k){
			LL ans=1;
			for(LL i=l;i<=r;i++)
				if(gcd(i,k)==1)
					ans=ans*i%k;
			printf("Case #%d: %lld\n",cas++,ans);
			continue;
		}
		LL ans=1;
		for(int i=1;i<k;i++)
			if(gcd(i,k)==1)
				ans=ans*i%k;
		LL len=(r-l+1)/k;
		LL res=(r-l+1)%k;
		ans=qpow(ans,len,k);
		for(LL i=l%k;res;res--){
			if(gcd(i,k)==1)
				ans=ans*i%k;
			i=(i+1)%k;
		}
		printf("Case #%d: %lld\n",cas++,ans);
	}
}


