#include<bits/stdc++.h>
using namespace std;
int n,A[110];
int main(){
	scanf("%d",&n);
	if(n%2==0)return 0*printf("NO");
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	int flg1=0,flg2=0;
	for(int i=1;i<=n;i++)	
		if(A[i]%2==0)flg1=1;
		else break;
	for(int i=n;i>=1;i--)
		if(A[i]%2==0)flg2=1;
		else break;
	if(flg1==0&&flg2==0)puts("YES");
	else puts("NO");
}


