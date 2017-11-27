#include<bits/stdc++.h>
using namespace std;
int A[100100];
map<int,int>mp;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),mp[A[i]]++;
	sort(A+1,A+1+n);
	long long r1=-1,r2=-1;
	for(int i=n;i>=1;i--){
		if(r1==-1&&mp[A[i]]>=2)r1=A[i];
		else if(r2==-1&&1LL*A[i]!=r1&&mp[A[i]]>=2&&r1!=-1){
			cout<<1LL*A[i]*r1<<endl;
			return 0;
		}
		else if(r2==-1&&mp[A[i]]>=4){
			cout<<A[i]*r1<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
}


