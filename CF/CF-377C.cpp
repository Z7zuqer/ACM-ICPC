#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	LL b,d,s;
	cin>>b>>d>>s;
	LL ans=0;
	if(b>=d&&b>=s){
		b--;
		ans+=max(0LL,b-d)+max(0LL,b-s);
	}
	else if(d>=s&&d>=b){
		d--;
		ans+=max(0LL,d-s)+max(0LL,d-b);
	}
	else if(s>=b&&s>=d){
		s--;
		ans+=max(0LL,s-d)+max(0LL,s-b);
	}
	cout<<ans<<endl;
}


