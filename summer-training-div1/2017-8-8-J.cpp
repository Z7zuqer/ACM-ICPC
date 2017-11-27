#include<bits/stdc++.h>
using namespace std;
char s[1001000];
int sum[1001000],que[1000100];
int main(){
	scanf("%s",s+1);
	for(int i=1;s[i];i++)sum[i]=sum[i-1]+(s[i]=='1');
	int n=strlen(s+1),maxm=n-sum[n];
	int q;
	scanf("%d",&q);
	while(q--){
		int k,T=1,H=1,ans=0;que[T]=0;
		scanf("%d",&k);
		for(int i=1;i<=n;i++){
			while(T<=H&&sum[i]-sum[que[T]]>k)T++;
			if(T<=H)ans=max(ans,i-sum[i]-(que[T]-sum[que[T]])+k-(sum[i]-sum[que[T]]));
			while(T<=H&&i-2*sum[i]<=que[H]-2*sum[que[H]])H--;
			que[++H]=i;	
		}
		printf("%d\n",min(maxm,ans));
	}
}
