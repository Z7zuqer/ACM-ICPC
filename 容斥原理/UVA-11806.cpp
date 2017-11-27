#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int mod=1e6+7;
LL C[510][510];
int main(){
	int T;
	scanf("%d",&T);
	C[0][0]=1;
	for(int i=0;i<510;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	while(T--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		if(k>=n*m){
			printf("%d\n",1);
			continue;
		}
		LL ans=C[n*m][k];
		ans=(ans-2*C[(n-1)*m][k]+mod+mod)%mod;
		ans=(ans-C[n*(m-1)][k]+mod-C[n*(m-1)][k]+mod)%mod;
		ans=(ans+C[m*(n-2)][k])%mod;
		ans=(ans+C[(m-2)*n][k])%mod;
		ans=(ans-C[(n-2)*(m-1)][k]+mod-C[(n-2)*(m-1)][k]+mod)%mod;
		ans=(ans-C[(n-1)*(m-2)][k]+mod-C[(n-1)*(m-2)][k]+mod)%mod;
		printf("%lld\n",ans);
	} 
}


