#include<bits/stdc++.h>
using namespace std;
#define LL long long
int T;
const int mod=1e9+7;
LL pow(int a,int b){
	if(b<0)return 0;
	LL r=1,base=a;
	while(b){
		if(b&1)r=r*base%mod;
		base=base*base%mod;
		b>>=1;
	}
	return r;
}
int main(){
	freopen("azerah.in","r",stdin);
	freopen("azerah.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int cnt=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(x&1)cnt++;
		}	
		LL r=pow(2,n)-1;
		LL ans=(r-pow(2,cnt-1)*pow(2,n-cnt)%mod)%mod;
		ans=(ans+mod)%mod;
		cout<<ans<<endl;
	}
}


