#include<bits/stdc++.h>
using namespace std;
struct 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	int ans=1e9;
	for(int i=2;i<=n-1;i++){
		vis[i]=1;
		ans=min(ans,work());
		vis[i]=0;
	}
	cout<<ans<<endl;
}


