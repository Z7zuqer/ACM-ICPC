#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int r1=a%3==0?1:0;
	int r2=b%3==0?1:0;
	if((b-a)/3+r1+r2-1>(b-a)/2+1)cout<<3<<endl;
	else cout<<2<<endl;
}


