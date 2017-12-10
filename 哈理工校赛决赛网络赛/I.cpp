#include<bits/stdc++.h>
using namespace std;
char s[1010101];
long long fac[62];
int bit[66];
int main(){
	int T,cas=1;
	fac[0]=1;
	for(int i=1;i<=60;i++)fac[i]=fac[i-1]*2;
	scanf("%d",&T);
	while(T--){
		int k;
		scanf("%d",&k);
		scanf("%s",s);
		memset(bit,0,sizeof bit);
		int len=strlen(s);
		long long maxm=0;
		int anslen=0;
		for(int i=0;i<len;i++){
			if(s[i]=='0')continue;
			long long sum=0;
			int nowlen=len-i,flg=0;
			nowlen=min(nowlen,k);
			if(nowlen<anslen)break;
			for(int j=0;j<k;j++){
				if(i+j>=len)break;
				if(s[i+j]-'0'<bit[j]){
					flg=1;
					break;
				}
				else if(bit[j]<s[i+j]-'0'){
					bit[j]=s[i+j]-'0';
					for(int t=j+1;t<nowlen;t++)bit[t]=s[i+t]-'0';
					anslen=nowlen;
					flg=1;
					break;
				}
				bit[j]=s[i+j]-'0';
			}
			if(!flg)anslen=nowlen;
		}
		for(int i=0;i<anslen;i++)maxm+=fac[anslen-i-1]*bit[i];
		printf("Case #%d: %lld\n",cas++,maxm);
	}
}


