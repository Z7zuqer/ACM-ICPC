#include<bits/stdc++.h>
using namespace std;
char mp[101][101];
int vis[101];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		map<int,int>mpp;
		for(int j=1;j<=m;j++)
			if(mp[i][j]=='#')
				mpp[j]=1;
		for(int k=i+1;k<=n;k++){
			int flg=0;
			for(int j=1;j<=m;j++){
				if(mp[k][j]=='#'&&mpp[j]==1){
					flg=1;
					break;
				}
			}
			if(flg==1){
				for(int j=1;j<=m;j++){
					if(mpp[j]==1&&mp[k][j]=='.')return 0*printf("No\n");
					if(mpp[j]==0&&mp[k][j]=='#')return 0*printf("No\n");
				}
				vis[k]=1;
			}
		}
	}
	puts("Yes");
}


