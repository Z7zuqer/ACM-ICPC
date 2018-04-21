#include<bits/stdc++.h>
using namespace std;
int A[101010];
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		ans^=A[i];
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ans^=A[x];
		A[x]=y;
		ans^=A[x];
		if(ans!=0)puts("Kan");
		else puts("Li");
	}
}


