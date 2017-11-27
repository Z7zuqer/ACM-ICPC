#include<bits/stdc++.h>
using namespace std;
char s[101][101];
int n,vis[101][101];
int cal(int x,int y){
	if(x==n/2+1&&y==n/2+1)return 0;
	map<char,int>mp;
	int k=0;
	int x1=n-x+1,y1=y;
	int x2=x,y2=n-y+1;
	int x3=n-x+1,y3=n-y+1;
	mp[s[x][y]]++;k=max(mp[s[x][y]],k);
	mp[s[x1][y1]]++;k=max(mp[s[x1][y1]],k);
	mp[s[x2][y2]]++;k=max(mp[s[x2][y2]],k);
	mp[s[x3][y3]]++;k=max(mp[s[x3][y3]],k);
	vis[x][y]=vis[x1][y1]=vis[x2][y2]=vis[x3][y3]=1;
	return 4-k;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int ans=0;
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		for(int i=1;i<n;i++){
			int x1=i,y1=n/2+1,k=0;
			int x2=n-i+1,y2=n/2+1;
			int x3=n/2+1,y3=i;
			int x4=n/2+1,y4=n-i+1;
			vis[x1][y1]=1;vis[x2][y2]=1;vis[x3][y3]=1;vis[x4][y4]=1;
			map<char,int>mp;
			mp[s[x4][y4]]++;k=max(mp[s[x4][y4]],k);
			mp[s[x1][y1]]++;k=max(mp[s[x1][y1]],k);
			mp[s[x2][y2]]++;k=max(mp[s[x2][y2]],k);
			mp[s[x3][y3]]++;k=max(mp[s[x3][y3]],k);
			ans+=4-k;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(!vis[i][j])ans+=cal(i,j);
		cout<<ans<<endl;
	}
}


