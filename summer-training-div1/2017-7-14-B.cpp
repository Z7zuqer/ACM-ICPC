#include<bits/stdc++.h>
using namespace std;
int n,m,height[110][110];
char s[110][110];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++)
			height[i][j]=s[i][j]-'0';
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(height[i][j])ans+=4*height[i][j]+2;
			for(int k=0;k<4;k++)
				ans-=min(height[i+dx[k]][j+dy[k]],height[i][j]);
		}
	cout<<ans<<endl;
}


