#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=1000000+123;
LL n,nextn[maxn],cnt[maxn];
char s[maxn];
void getnext(){
	int i=0,j=-1;
	nextn[0]=-1;
	while(i<n){
		if(j==-1||s[i]==s[j]){
			++i;++j;nextn[i]=j;
		}
		else j=nextn[j];
	}
}
int main(){
	scanf("%s",s);
	n=strlen(s);
	getnext();
	int ans=n-nextn[n];
	cout<<ans<<endl;
}
