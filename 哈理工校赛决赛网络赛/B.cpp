#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int maxm=-1;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			maxm=max(maxm,x);
		}
		printf("%d\n",maxm); 
	} 
}


