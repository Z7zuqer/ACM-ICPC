#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[200100],sum[2][200100];
int main(){
	int n,k;
	scanf("%d%d",&n,&k); 
	for(int i=1;i<=n;i++)scanf("%lld",&A[i]);
	for(int i=1;i<=n;i++){
		if(i&1){
			sum[1][i]=sum[1][i-2]+A[i];
			sum[0][i]=sum[0][i-1];
		}
		else {
			sum[0][i]=sum[0][i-2]+A[i];
			sum[1][i]=sum[1][i-1];
		}
	}
	LL ans=0;
	int x=k&1;
	//for(int i=1;i<=n;i++)cout<<sum[0][i]<<" "<<sum[1][i]<<endl;
	for(int i=1;i<=n;i++){
		int suc=i+k-1;suc=min(suc,n);
		int pre=i-k+1;pre=max(1,pre);
		cout<<pre<<" "<<suc<<endl;
		ans+=sum[(i&1)&x][suc]-sum[(i&1)&x][pre-1];
	}
	printf("%lld\n",ans);
}


