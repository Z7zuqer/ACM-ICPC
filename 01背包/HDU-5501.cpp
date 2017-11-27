#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}r[1010];
int cmp(node m,node n){
	return m.b>n.b;
}
int dp[4010];
void show(int n){
	for(int i=1;i<=n;i++)cout<<dp[i]<<" ";cout<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,t;
		scanf("%d%d",&n,&t);
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&r[i].a,&r[i].b,&r[i].c);
		} 
		sort(r+1,r+1+n,cmp);
		for(int i=1;i<=n;i++){
			for(int j=t;j>=r[i].c;j--)
				dp[j]=max(dp[j],dp[j-r[i].c]+r[i].a-(j)*r[i].b);
			show(t);
		}
		int ans=0;
		for(int i=0;i<=t;i++)ans=max(ans,dp[i]);
		cout<<ans<<endl;
	}
}
/*
28 26 24 22 20 18 16 14 12 10
28 44 69 64 59 54 49 44 39 34
28 44 69 64 59 54 49 44 65 88
28 44 69 64 59 54 49 48 72 88
*/



