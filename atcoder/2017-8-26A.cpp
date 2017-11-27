#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	LL q,h,s,d,n;
	cin>>q>>h>>s>>d>>n;
	LL ans=1e18;
	ans=min(ans,n*4*q);
	ans=min(ans,n*2*h);
	ans=min(ans,n*s);
	long long res=0;
	if(n&1)res=min(s,min(h*2,q*4));
	ans=min(ans,n/2*d+res);
	cout<<ans<<endl;
}


