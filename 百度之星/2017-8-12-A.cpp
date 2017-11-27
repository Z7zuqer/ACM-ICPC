#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long p;
		cin>>p;
		long long ans=p/3;
		if(p%3==0)ans++;
		cout<<ans<<endl;
	} 
}


