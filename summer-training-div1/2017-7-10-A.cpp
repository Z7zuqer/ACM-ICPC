#include<bits/stdc++.h>
using namespace std;
char A[81234],B[81234];
int main(){
	int n,x,y,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%s%s",&n,&x,&y,A,B);
		int same=0;
		for(int i=0;i<n;i++)
			if(A[i]==B[i])
				same++;
		if(x==y){
			if(same>=x)puts("Not lying");
			else {
				if((x-same)*2+same<=n)puts("Not lying");
				else puts("Lying");
			}
		}
		else {
			int a=x,b=y;
			x=max(a,b);y=min(a,b);
			if(same>=y){
				if(n-same>=x-y)puts("Not lying");
				else puts("Lying");
			}
			else {
				if(y-same+x-same<=n-same)puts("Not lying");
				else puts("Lying");
			}
		}
	} 
}


