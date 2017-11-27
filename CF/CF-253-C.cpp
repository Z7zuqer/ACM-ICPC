#include<bits/stdc++.h>
using namespace std;
int X[110],Y[110],cnt[3020],res[11],vis[110];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char s[3];
		scanf("%s",s);
		if(s[0]=='R')X[i]=0;
		if(s[0]=='B')X[i]=1;
		if(s[0]=='Y')X[i]=2;
		if(s[0]=='W')X[i]=3;
		if(s[0]=='G')X[i]=4;
		Y[i]=s[1]-'0'+4;
	}
	int minv=11,all_sta=1<<10;
	for(int sta=0;sta<all_sta;sta++){
		if(sta)cnt[sta]=cnt[sta/2]+(sta&1);
		memset(vis,0,sizeof vis);
		int flg=0;
		for(int i=1;i<=n;i++){
			if((sta>>X[i])&1)vis[i]|=1<<X[i];
			if((sta>>Y[i])&1)vis[i]|=1<<Y[i];
			for(int j=1;j<i;j++)
				if(vis[i]==vis[j]&&(X[i]!=X[j]||Y[i]!=Y[j])){
					flg=1;
					break;
				}
		}
		if(!flg)minv=min(minv,cnt[sta]);
	}
	printf("%d\n",minv);
}
