#include<bits/stdc++.h>
using namespace std;
#define LL long long 
LL A[300100],sum[300100];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&A[i]);
	sort(A+1,A+1+n);
	for(int i=n;i>=1;i--)sum[i]=sum[i+1]+A[i];
	LL ans=sum[1];
	for(int i=1;i<=n;i++){
		//ans+=sum[i];
		if(i<n-1)ans+=A[i],ans+=sum[i+1];
		else break;
		//cout<<ans<<" "<<i<<endl;
	}
	if(n>=2)ans+=A[n]+A[n-1];
	printf("%I64d\n",ans);
}


