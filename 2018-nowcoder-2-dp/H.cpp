#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL F[1010]={0,0,1,1,2};
LL f(int k){
	if(F[k]>0)return F[k];
	if(k<=3)return F[k];
	return F[k]=f(k-1)+f(k-2)+f(k-3);
} 
int main(){
	int n;
	while(~scanf("%d",&n))printf("%I64d\n",f(n));
}


