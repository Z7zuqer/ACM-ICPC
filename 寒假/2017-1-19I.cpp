#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	freopen("perechi3.in","r",stdin);
	freopen("perechi3.out","w",stdout);
	int T;
	LL n;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		LL ans=0;
		int k=sqrt(n);
		for(int i=1;i<=k;i++)
			ans+=2*(int)(n/i);
		ans-=k*k;
		printf("%lld\n",ans);
	}
}


