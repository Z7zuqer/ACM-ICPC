#include<bits/stdc++.h>
using namespace std;
#define LL long long
const double req=sqrt(2.0);
int check(LL k,int area){
	if(k&1){
		LL rem=k-1;
		LL tmp=k/2;
		LL x=tmp/2;
		LL y=tmp-x;	
		if(x==0||y==0)return 0;
		if(x>1&&2*x*y+(x+2.0)/2.0>=area*1.0)return 1;
		if(y>1&&2*x*y+(y+2.0)/2.0>=area*1.0)return 1;
	}
	else {
		LL rem=k/2;
		LL x=rem/2;
		LL y=rem-x;
		if(2*x*y>=area*1LL)return 1;
	}
	return 0;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int k;
		scanf("%d",&k);
		LL l=1,r=1e18;
		while(l<r){
			LL mid=(l+r)>>1;
			if(check(mid,k))r=mid;
			else l=mid+1;
		}
		printf("%lld\n",r);
	} 
}


