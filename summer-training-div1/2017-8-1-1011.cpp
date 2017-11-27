#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	int ans=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		int x;
		cin>>x;
		if(x<=35)ans++;
	}
	cout<<ans<<endl;
}


