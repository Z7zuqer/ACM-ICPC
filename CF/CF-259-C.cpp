#include<bits/stdc++.h>
using namespace std;
#define LL long long
const double eps=1e-10;
double qpow(double a,LL b){
	double ans=1,base=a;
	if(a<eps)return 0;
	while(b){
		if(b&1)ans=ans*base;
		base=base*base;
		if(base<eps)return ans;
		b>>=1;
	}
	return ans;
} 
int main(){
	LL n,m;
	scanf("%I64d%I64d",&m,&n);
	double ans=m;
	for(int i=m-1;i>=1;i--){
		double res=qpow(i*1.0/m,n);
		if(res<eps)break;
		ans-=res;
	}
	printf("%.5lf\n",ans);
}


