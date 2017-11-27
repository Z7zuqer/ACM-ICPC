#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[100100],dp[100100][2];
LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&A[i]);
	LL div=A[1],ans=0;
	for(int i=2;i<=n;i++)div=gcd(div,A[i]);
	if(div>1)return 0*printf("YES\n0\n");
	for(int i=1;i<=n;i++)
		if((A[i]&1)&&(A[i+1]&1))ans++,A[i+1]=0;
		else if((A[i]&1)&&(!(A[i+1]&1)))ans+=2;
	cout<<"YES"<<endl<<ans<<endl;
}


