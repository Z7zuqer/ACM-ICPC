#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,cas=1;
	while(~scanf("%d",&n)){
		int ans=1+(int)floor(n*log(2)/log(10));
		printf("Case #%d: %d\n",cas++,ans-1);
	}
}


