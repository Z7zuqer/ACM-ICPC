#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		long long ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			ans+=a*b;
		}
		cout<<ans<<endl;
	}
}


