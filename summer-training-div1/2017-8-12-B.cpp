#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=2001000;
const int mod=1e9+7;
int len,len1,len2,NEXT[maxn];
LL dp[maxn];
char s1[maxn],s2[maxn],s[maxn];
void getNEXT(){
	for(int i=1,k=0;s[i];i++){
		while(k>0&&s[i]!=s[k])k=NEXT[k-1];
		while(k>0&&s[i]==s[k]&&k==len2)k=NEXT[k-1];
		while(k>0&&s[i]==s[k]&&i>=len2&&i-k<len2)k=NEXT[k-1];
		if(s[i]==s[k])k++;
		NEXT[i]=k;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(NEXT,0,sizeof NEXT);
		memset(dp,0,sizeof dp);
		scanf("%s%s",s1,s2);
		len=0,len1=strlen(s1),len2=strlen(s2);
		for(int i=len2-1;i>=0;i--)s[len++]=s2[i];
		for(int i=len1-1;i>=0;i--)s[len++]=s1[i];
		s[len]='\0';
		getNEXT();
		for(int i=1;i<len;i++)dp[i]=(dp[NEXT[i]-1]+1LL*NEXT[i])%mod;
		LL ans=0;
		for(int i=len2;i<len;i++)ans=(ans+dp[i])%mod;
		printf("%lld\n",ans);
	}
}
