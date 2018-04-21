#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[500100],sum;
int main(){
	int q,res=0,now=0;
	scanf("%d",&q);
	while(q--){
		int k;
		scanf("%d",&k);
		if(k==1){
			scanf("%lld",&A[++now]); 
			while(res<now&&sum+A[now]>A[res+1]*(res+1)){
				res++;
				sum+=A[res];
			}
		}
		else {
			double ans=A[now]-1.0*(sum+A[now])/(res+1);
			printf("%.8f\n",ans);
		}
	}
}


