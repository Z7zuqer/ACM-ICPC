#include<bits/stdc++.h>
using namespace std;
int A[1010][1010];
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			if(i==j)ans+=x;
		}
	ans%=2;
	int q;
	scanf("%d",&q);
	while(q--){
		int k,x;
		scanf("%d",&k);
		if(k==1)scanf("%d",&x),ans^=1;
		if(k==2)scanf("%d",&x),ans^=1;
		if(k==3)printf("%d",ans);
	}
}


