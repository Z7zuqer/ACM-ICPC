#include<bits/stdc++.h>
using namespace std;
#define LL long long 
const int mod=1e9+7;
LL A[1010][2];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++)scanf("%lld%lld",&A[i][0],&A[i][1]);
		LL ans=0;
		for(int i=1;i<=n;i++){
			if(i==1)ans=A[i][0]+A[i][1];
			else ans=ans*(A[i][0]+A[i][1])%mod;
		}
		printf("%lld\n",ans);
	}
}


