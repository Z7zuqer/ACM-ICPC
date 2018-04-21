#include<bits/stdc++.h>
using namespace std;
int n;
int A[5010];
int check(int i){
	if(A[A[A[i]]]==i)return 1;
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	for(int i=1;i<=n;i++){
		if(check(i)){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}


