#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,m,A[1010],B[1010]; 
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	scanf("%d",&m);for(int i=1;i<=m;i++)scanf("%d",&B[i]);
	LL ans=1e9*9;
	for(int i=1;i<=m-n+1;i++){
		LL k=0;
		for(int j=0;j<n;j++)k+=1LL*(A[1+j]-B[i+j])*(A[1+j]-B[i+j]);
		ans=min(ans,k);
	}
	cout<<ans<<endl;
}


