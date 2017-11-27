#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,m,w,A[100010],B[100010],C[100010];
int check(LL x){
	LL rem=m,sum=0;
	memset(C,0,sizeof C);
	for(int i=1;i<=n;i++){
		B[i]=A[i];
		B[i]+=sum;
		if(C[i]>0)sum-=C[i];
		if(B[i]<x){
			if(w-1>0)sum+=(x-B[i]);
			C[min(n,i+w-1)]=x-B[i];
			rem-=(x-B[i]);
		}
		if(rem<0)return 0;
	}
	if(rem<0)return 0;
	return 1;
}
int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&w);
	for(int i=1;i<=n;i++)scanf("%I64d",&A[i]);
	LL l=1,r=1e10,res=1;
	while(l<=r){
		LL mid=(l+r)>>1,tmp=0;
		if(tmp=check(mid))l=mid+1,res=mid;
		else r=mid-1;
	}
	printf("%I64d\n",res);
}
