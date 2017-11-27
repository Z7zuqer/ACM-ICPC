#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	int T;
	LL n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d",&n,&m);
		//LL all=n*(n-1)/2*n;
		if(m>=(n-1)*n/2)printf("%I64d\n",n*(n-1));
		else if(m>=n-1){
			LL ans=n-1;
			ans+=n-1;
			//cout<<ans<<endl;
			ans+=(n-1)*(n-1-1)*2;
			//cout<<ans<<endl;
			m-=n-1;
			ans-=m*2;
			printf("%I64d\n",ans);
		}
		else {
			LL rem=n-1-m;
			LL ans=rem*(n-1)*n*2;
			ans-=(rem-1)*(rem)*n;
			LL rem_n=m;
			LL pair=(rem_n)*(rem_n-1);
			ans+=pair*2;
			ans+=m*2;
			printf("%I64d\n",ans);
		}
	}
}


