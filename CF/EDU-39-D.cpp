#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char s[510][510];
int minv[510],dp[510][510];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		vector<int>v;
		for(int j=1;j<=m;j++)
			if(s[i][j]=='1')
				v.push_back(j);
		int res=v.size();
		if(res==0)
			minv[0]=0;
		else {
			for(int j=0;j<=k;j++)minv[j]=1e9;
			minv[0]=v[res-1]-v[0]+1;
			minv[res]=0;
			for(int j=1;j<res;j++){
				for(int t=0;t<=j;t++){
					//cout<<res-1-j+t<<" "<<t<<endl;
					minv[j]=min(minv[j],v[res-1-(j-t)]-v[t]+1);
				}
			}
		}
		//cout<<i<<": ";
		//for(int j=0;j<=res;j++)cout<<minv[j]<<" ";cout<<endl;
		if(i==1){
			for(int j=0;j<=k;j++){
				if(j<=res){
					dp[1][j]=minv[j];
				}
				else {
					dp[1][j]=1e9;
				}
			}
		}
		else {
			for(int j=0;j<=k;j++)dp[i][j]=dp[i-1][j]+minv[0];
			for(int j=0;j<=res;j++){//i use skip
				for(int t=0;t<=k-j;t++){//i-1 state
					dp[i][j+t]=min(dp[i-1][t]+minv[j],dp[i][j+t]);
				}
			}
		}
	}
	int ans=1e9;
	for(int i=0;i<=k;i++)ans=min(ans,dp[n][i]);
	printf("%d\n",ans);
}


