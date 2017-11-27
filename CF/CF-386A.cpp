#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int ans=a;
	ans=min(ans,b/2);
	ans=min(ans,c/4);
	cout<<ans*7<<endl;
} 
