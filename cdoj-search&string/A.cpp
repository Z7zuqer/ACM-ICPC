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
	nextn[0]=0;
}
void update(LL &a,LL b){
	a+=b;
	while(a>10007)a-=10007;
}
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	getnext();
	LL ans=0;
	for(int i=1;i<=n;i++){
		cnt[i]=cnt[nextn[i]]+1;
		update(ans,cnt[i]);
	}
	cout<<ans<<endl;
}
