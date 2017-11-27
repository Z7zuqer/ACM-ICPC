#include<bits/stdc++.h>
using namespace std;
int A[1010];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	long long ans=0;
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		ans+=min(A[a],A[b]);
	}
	cout<<ans<<endl;
}
