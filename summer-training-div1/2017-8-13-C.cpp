#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=100100;
LL phi[maxn],sum[maxn];
void pre(){
    for(int i=1;i<maxn;i++)phi[i]=i;
    for(int i=2;i<maxn;i+=2)phi[i]/=2;
	for(int i=3;i<maxn;i+=2){
		if(phi[i]==i){
			for(int j=i;j<maxn;j+=i){
				phi[j]=1LL*phi[j]/i*1LL*(i-1);
			}
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	pre();
	for(int i=1;i<maxn;i++)sum[i]=sum[i-1]+phi[i];
	//for(int i=1;i<20;i++)cout<<phi[i]<<endl;
	while(T--){
		LL n;
		scanf("%lld",&n);
		LL sum1=1LL*(1+n)*n/2;
		LL sum2=sum[n];
		printf("%lld\n",sum1-sum2);
	}
}


