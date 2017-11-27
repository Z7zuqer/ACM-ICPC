#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[300100],S[300100];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&A[i]);
	if(n==2){
		cout<<abs(A[2]-A[1])<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)S[i]=S[i-1]+A[i];
	LL minm=1e15;
	for(int i=2;i<n;i++){
		if(abs(S[n]-S[i]-S[i])<minm)
			minm=abs(S[n]-S[i]-S[i]);
	}
	cout<<minm<<endl;
}


