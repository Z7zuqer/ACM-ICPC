#include<bits/stdc++.h>
using namespace std;
const long long mod=100003;
long long n,m;
long long qpow(long long a,long long b){
	long long base=a%mod,r=1;
	while(b){
		if(b&1)r=r*base%mod;
		base=base*base%mod;
		b>>=1;
	}
	return r;
}
int main(){
	//cout<<qpow(2,4);
	cin>>m>>n;
	long long ans=(qpow(m,n)-(m*qpow(m-1,n-1))%mod);
	if(ans<0)ans+=mod;
	cout<<ans<<endl;
} 
