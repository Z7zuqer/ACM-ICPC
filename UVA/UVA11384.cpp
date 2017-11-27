#include<bits/stdc++.h>
using namespace std;
int r(int n){
	if(n==1)return 1;
	return r(n/2)+1;
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		cout<<r(n)<<endl;
	}
}
