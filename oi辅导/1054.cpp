#include<bits/stdc++.h>
using namespace std;
int dx[8]={-1,1,0,0,1,1,-1,-1};
int dy[8]={0,0,1,-1,1,-1,1,-1};
char mp[310][310];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='*'){
				putchar('*');
				continue;
			}
			int cnt=0;
			for(int k=0;k<8;k++){
				int tx=i+dx[k];
				int ty=j+dy[k];
				if(tx>=1&&ty>=1&&tx<=n&&ty<=m&&mp[tx][ty]=='*')cnt++;
			}
			printf("%d",cnt);
		}
		puts("");
	}
}


