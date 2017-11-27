#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[10000000];
int main(){
	LL n,k;
	scanf("%I64d%I64d",&n,&k);
	int num=0;
	LL s=sqrt(n);
	for(LL i=1;i<=s;i++)
		if(n%i==0){
			if(i==n/i)A[num++]=i;
			else{
				A[num++]=i;
				A[num++]=n/i;	
			}
		}
	if(k>num)return 0*printf("-1\n");
	nth_element(A,A+k-1,A+num);
	cout<<A[k-1]<<endl;
}


