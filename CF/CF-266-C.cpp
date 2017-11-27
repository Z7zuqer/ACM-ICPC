#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[500100],sum[500100];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&A[i]);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+A[i];
	if(sum[n]%3!=0)return 0*printf("0\n");
	LL div=sum[n]/3;
	int l=1,r=n,ans=0;
	LL suml=A[1],sumr=A[n];
	while(l<r&&r<=n){
		while(l<r&&suml!=div)suml+=A[++l];
		while(l<r&&sumr<=div){
			if(sumr==div&&suml==div)ans++;
			sumr+=A[--r];
		}
	//	if(l<r&&suml==div&&sumr==div)ans++;
		l++;suml+=A[l];
	}
	cout<<ans<<endl;
}


