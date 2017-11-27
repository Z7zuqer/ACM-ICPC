#include<bits/stdc++.h>
using namespace std;
int A[101010];
int main(){
	int now=1,n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	sort(A+1,A+1+n,greater<int>());
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,i+A[i]);
	cout<<ans+1<<endl;
}


