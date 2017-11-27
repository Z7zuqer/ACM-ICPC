#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL sum[1000100],A[1000100];
int main(){
	int n;
	scanf("%d",&n);
	LL sum=0;
	for(int i=1;i<=n;i++)scanf("%I64d",&A[i]),sum+=A[i];
	if(sum&1)return 0*printf("First");
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(A[i]&1)cnt++;
	}
	if(cnt>0)return 0*printf("First");
	puts("Second");
}


