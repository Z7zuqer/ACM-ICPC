#include<bits/stdc++.h>
using namespace std;
string A[100];
int cmp(string a,string b){
	if(a+b>b+a)return 0;
	return 1;
}
int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		for(int i=1;i<=n;i++)cin>>A[i];
		sort(A+1,A+1+n,cmp1);
		for(int i=n;i>=1;i--)cout<<A[i];
		cout<<endl;
	}
}


