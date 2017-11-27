#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int k=gcd(n,m);
	if(k!=1)return 0*printf("No\n");
	else puts("Yes");
}


