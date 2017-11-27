#include<bits/stdc++.h>
using namespace std;
const int maxn=200050;
int a[maxn],num[maxn];
int main(){
	int n,mod,b,len=0,size=0,lst=0;
	scanf("%d%d",&n,&mod);
	char s[2];
	while(n--){
		scanf("%s%d",s,&b);
		if(s[0]=='A'){
			b=(b+lst)%mod;
			num[++len]=b;
			while(size&&num[a[size]]<=b)size--;
			a[++size]=len;
		}
		else {
			int pos=lower_bound(a,a+size,len-b+1)-a;
			printf("%d\n",lst=num[a[pos]]);
		}
	}
}
