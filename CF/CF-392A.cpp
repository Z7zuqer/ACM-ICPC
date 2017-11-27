#include<bits/stdc++.h>
using namespace std;
int A[110]; 
int main(){
	int n,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		sum=max(sum,A[i]);
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=abs(sum-A[i]);
	}
	cout<<ans<<endl;
}


