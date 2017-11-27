#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		ans+=x/2;
	}
	if(ans%2==1)cout<<"Daenerys"<<endl;
	else cout<<"Stannis"<<endl;
}


