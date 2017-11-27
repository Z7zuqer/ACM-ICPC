#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL check(LL mid){
	if(mid>1e9)return 0;
	return (1LL+mid)/2*mid;
}
int main(){
	LL n;
	scanf("%I64d",&n);
	if((n+2)%3)return 0*printf("0\n");
	LL div=(n+2)/3;
	LL l=1,r=n,res=0;
	while(l<=r){
		LL mid=(l+r)>>1;
		if(check(mid)>div)r=mid-1;
		else l=mid+1,res=mid;
	}
	printf("%I64d\n",res-1); 
}


