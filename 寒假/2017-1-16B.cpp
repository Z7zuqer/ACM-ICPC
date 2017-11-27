#include<bits/stdc++.h>
using namespace std;
int n;
int A[110];
int work(int k){
	int mx=-1,s=0;
	for(int i=1;i<=n;i++){
		s+=A[i];
		mx=max(mx,A[i]);
		if(A[i]>k)return 0;
	}
	if(k<s*2)return 0;
	return k/mx+1;
}
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		cout<<work(50)<<" "<<work(60)<<" "<<work(70)<<endl;
	}
}


