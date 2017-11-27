#include<bits/stdc++.h>
using namespace std;
int X[1010],Y[1010];
int main(){
	int n,cas=1;
	while(scanf("%d",&n)&&n){
		for(int i=1;i<=n;i++)scanf("%d%d",&X[i],&Y[i]);
		sort(X+1,X+1+n);
		sort(Y+1,Y+1+n);
		int mid;
		if(n&1)mid=n/2+1;
		else mid=n/2;
		//int mid=n/2+1;
		int midx=X[mid],midy=Y[mid];
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans+=abs(X[i]-midx)*1LL+abs(Y[i]-midy)*1LL;
		}
		printf("Case %d: (%d,%d) %I64d\n",cas++,midx,midy,ans);
	} 
}


