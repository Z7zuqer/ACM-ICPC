#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b); 
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	//if(b%a!=0&&a%b!=0)return 0*printf("NO\n");
	//if(a>b)swap(a,b);
	int r=gcd(a,b);
	for(int i=1;i<r;i++){
		int k=sqrt(r*r-i*i);
		if(k>0&&k*k+i*i==r*r){
			//if(k==i)continue;
			if(i*(a/r)==k*(b/r))continue;
			puts("YES");
			printf("0 0\n");
			printf("%d %d\n",-k*(a/r),-i*(a/r));
			printf("%d %d\n",(i)*(b/r),(-k)*(b/r));
			return 0;
		}
	}
	puts("NO");
}


