#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	LL n;
	int k;
	scanf("%lld%d",&n,&k);
	LL maxv=1e18;
	LL ans=-1;
	int type=-1;
	for(int i=1;i<=k;i++){
		LL x;
		scanf("%lld",&x);
		if((n%x)<maxv){
			maxv=n%x;
			ans=x;
			type=i;
		}
	}
	printf("%d %lld\n",type,n/ans);
}


