#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		int maxm=-1e9+1,mx=-1e9+1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mx=max(mx,maxm-a[i]);
			maxm=max(maxm,a[i]);
		}
		cout<<mx<<endl;
	}
}


