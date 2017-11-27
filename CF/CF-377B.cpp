#include<bits/stdc++.h>
using namespace std;
int A[510],B[510];
int main(){
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),sum+=A[i];
	int tmp=0;
	for(int i=1;i<n;i++){
		if(A[i]+A[i+1]<k)A[i+1]+=k-A[i]-A[i+1];
		tmp+=A[i];
	}
	tmp+=A[n];
	cout<<tmp-sum<<endl;
	for(int i=1;i<=n;i++)cout<<A[i]<<" ";
}


