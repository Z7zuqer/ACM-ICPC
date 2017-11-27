#include<bits/stdc++.h>
using namespace std;
int main(){
	double n;
	int t;
	scanf("%d",&t);
	while(t--){
		cin>>n;
		n+=1LL;
		while(n>18)n/=18;
		if(n<=9)puts("YES");
		else puts("NO");
	}
}


