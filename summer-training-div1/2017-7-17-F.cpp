#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
const double t=sqrt(3);
double qpow(int k){
	double base=7+4.0*t;
	double ans=1;
	while(k){
		if(k&1)ans*=base;long long r=ans/mod;ans-=r*mod;
		base*=base;long long r2=ans/mod;ans-=r2*mod;
		k>>=1;
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	int t_=clock();
	while(t--){
		int n=1000000000;
		cout<<(long long)qpow(n)<<endl;
	}
	cout<<clock()-t<<endl;
}


