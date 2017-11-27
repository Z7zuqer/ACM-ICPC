#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin>>a;
	int k=sqrt(a);
	for(int i=k;i>=1;i--){
		if(a%i==0){
			cout<<i<<" "<<a/i<<endl;
			return 0;
		}
	}
}
