#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	LL a,b;
	scanf("%lld%lld",&a,&b);
	while(1){
		if(a==0||b==0)break;
		if(a>=2*b)a%=(b*2);
		if(a==0||b==0)break;
		if(b>=2*a)b%=2*a;
		else break;
	}
	cout<<a<<" "<<b<<endl;
}


