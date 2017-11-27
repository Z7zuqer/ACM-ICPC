#include<bits/stdc++.h>
using namespace std;
char s[507][2007];
int vis[507][507],cnt[507];
int main(){
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		int n,flg=0;
		scanf("%d",&n);
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)scanf("%s",s[i]);
		for(int i=n;i>=1&&!flg;i--){
			for(int j=1;j<i&&!flg;j++){
				if(strstr(s[i],s[j])==NULL){
					flg=i;
					break;
				}
				else vis[j][i]=1;
			}
		}
		printf("Case #%d: %d\n",cas++,flg==0?-1:flg);
	}	
}


