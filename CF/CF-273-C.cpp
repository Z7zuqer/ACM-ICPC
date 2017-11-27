#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,c;
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	long long ans=min(a,min(b,c));
	a-=ans;b-=ans;c-=ans;
	long long res=(a+b+c)/3;
	a=(a==0?2e9:a);
	b=(b==0?2e9:b);
	c=(c==0?2e9:c);
	if(res>=1)ans+=min(min(res,a),min(b,c));
	cout<<ans<<endl;
}
