#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int cnt=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(x&1)cnt++;
		}
		if(cnt>=n/2)cout<<2<<" "<<1<<endl;
		else cout<<2<<" "<<0<<endl;
	}
}


