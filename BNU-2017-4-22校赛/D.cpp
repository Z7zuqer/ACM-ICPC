#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL qpow(LL a,LL b){
	LL base=a,r=1;
	while(b){
		if(b&1)r*=base;
		base*=base;
		b>>=1;
	}
	return r;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int k=n*(n-1)/2;
		for(int i=1;i<n;i++)cout<<0<<endl;
		cout<<qpow(2LL,1LL*k)<<endl;
	}
}


