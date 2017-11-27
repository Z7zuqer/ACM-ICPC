#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+107;
char s[maxn];
int NEXT[maxn],len;
void preNEXT(){
	NEXT[0]=0;
	for(int i=1,k=0;s[i];i++){
		while(k>0&&s[i]!=s[k])k=NEXT[k-1];
		if(s[i]==s[k])k++;
		NEXT[i]=k;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(scanf("%d%s",&len,s)!=EOF){
		scanf("%d%s",&len,s);
		preNEXT();
		int ans=len%10007;
		ans=(ans+NEXT[len-1])%10007;
		for(int i=0;i<len-1;i++)
			if(NEXT[i]>0&&NEXT[i]!=NEXT[i+1]-1){
				ans=(ans+NEXT[i])%10007;
			}
		cout<<ans<<endl;
	}
}


