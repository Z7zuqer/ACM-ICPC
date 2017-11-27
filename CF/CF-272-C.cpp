#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	long long ans=0;
	for(int i=1;i<=a;i++){
		long long res=(1LL*i*b+1)%mod;
		long long req=1LL*b*(b-1)/2%mod;
		ans+=res*req%mod;
		ans%=mod;
	}
	cout<<ans<<endl;
}


