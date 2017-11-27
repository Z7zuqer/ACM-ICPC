#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int main(){
	int T;
	scanf("%d",&T);
	//cout<<work(1e9+7)<<endl;
	while(T--){
		long long a;
		scanf("%lld",&a);
		long long ans=(a+1)/2+1;
		printf("%lld\n",ans);
	}
}


