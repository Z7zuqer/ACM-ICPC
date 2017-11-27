#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	LL n,m,k;
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	if(k>n+m-2)return 0*printf("-1\n");
	if(n>m)swap(n,m); 
	if(k<=m-1){
		LL x=m/(k+1);
		LL y=n/(k+1);
		printf("%I64d\n",max(x*n,y*m));
	}
	else {
		LL x=1;
		LL y=n/(k-m+1+1);
		LL xx=m/(k-n+2);
		LL yy=1;
		printf("%I64d\n",max(xx*yy,x*y));
	}
	//minv=min(minv,work(x,y,m,n));
	return 0;
}


