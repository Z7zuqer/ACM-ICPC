#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,m;
LL k;
int check(LL v){
	LL cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=min(v/i,m*1LL);
		if(cnt>=k)return 1;
	}
	return cnt>=k;//das
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%I64d",&k);
	LL l=1,r=1LL*n*m*10;
	while(l<r){
		LL mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%I64d\n",r);
}
