#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[110],B[110];
int main(){
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%lld",&A[i]);
		for(int i=0;i<n;i++)scanf("%lld",&B[i]);
		if(B[0]>A[0]){
			printf("Case #%d: 0\n",cas++);
			continue;
		}
		int flg=0;
		LL minv=1e18;
		A[0]-=B[0];
		for(int i=0;i<n;i++){
			int L=(i-1+n)%n;
			if(B[i]-B[L]>0){
				flg=1;
				LL minm=A[i]/(B[i]-B[L]);
				minm=minm*n+i;
				if(i==0)minm+=n;
				minv=min(minv,minm);
			}
		}
		if(flg==0)printf("Case #%d: INF\n",cas++);
		else printf("Case #%d: %lld\n",cas++,minv);
	}
}


