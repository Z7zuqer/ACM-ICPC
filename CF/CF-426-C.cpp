#include<bits/stdc++.h>
using namespace std;
#define LL long long
void work(LL a,LL b,LL c){
	if(a%c==0&&b%c==0)puts("YES");
	else puts("NO");
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		LL a,b;
		scanf("%I64d%I64d",&a,&b);
		int flg=0;
		LL l=1,r=1e6,c=a*b;
		while(l<=r){
			LL mid=(l+r)>>1;
			LL tmp=mid*mid*mid;
			if(tmp>c)r=mid-1;
			else if(tmp<c)l=mid+1;
			else {
				work(a,b,mid);
				flg=1;
				break;
			}
		}
		if(!flg)puts("NO");
	}
}
