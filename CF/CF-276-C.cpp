#include<bits/stdc++.h>
using namespace std;
#define LL long long
int bits[100];
LL fac[300];
int main(){
	int n;
	scanf("%d",&n);
	fac[0]=1;
	for(int i=1;i<=63;i++)fac[i]=fac[i-1]*2;
	for(int i=1;i<=n;i++){
		LL l,r;
		scanf("%I64d%I64d",&l,&r);
		LL res=l;
		int len=0,maxv=0;
		memset(bits,0,sizeof bits);
		while(res){
			bits[++len]=res&1;
			res>>=1;
			if(bits[len])maxv++;
		}
		for(int i=1;i<=63;i++){
			if(fac[i-1]+l<=r&&bits[i]==0){
				l+=fac[i-1];
				maxv++;
			}
		}
		printf("%I64d\n",l);
	} 
}


