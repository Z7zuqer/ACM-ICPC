#include<bits/stdc++.h>
using namespace std;
#define LL long long
int check(LL n,LL k,LL d1,LL d2){
	LL div=n/3;
	if((k-d1+d2)%3)return 0;
	LL B=k-(d1-d2);B/=3;if(B<0||B>div||B>k)return 0;
	LL A=d1+B;if(A<0||A>div||A>k)return 0;
	LL C=B-d2;if(C<0||C>div||C>k)return 0;
	return 1;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		LL n,k,d1,d2,A,B,C;
		scanf("%I64d%I64d%I64d%I64d",&n,&k,&d1,&d2);
		if(n%3!=0){
			puts("no");
			continue;
		}
		//1
		if(check(n,k,d1,d2))puts("yes");
		else if(check(n,k,-d1,d2))puts("yes");
		else if(check(n,k,d1,-d2))puts("yes");
		else if(check(n,k,-d1,-d2))puts("yes");
		else puts("no");
	}
}


