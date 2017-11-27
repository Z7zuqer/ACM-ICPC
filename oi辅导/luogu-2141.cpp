#include<bits/stdc++.h>
using namespace std;
int A[110],B[1000000+7];
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	sort(A+1,A+1+n);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(!B[k]&&A[i]+A[j]==A[k]){
					B[k]=1;
					ans++;
				}
	printf("%d\n",ans);
}


