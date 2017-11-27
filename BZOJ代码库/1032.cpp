#include<bits/stdc++.h>
using namespace std;
const int maxn=550;
int dp[maxn][maxn],n,seq[maxn];
pair<int,int>arr[maxn];
int cnt=1;
int dfs(int l,int r){
	if(dp[l][r]!=-1)return dp[l][r];
	if(l>r)return dp[l][r]=0;
	if(arr[l].first==arr[r].first)dp[l][r]=dfs(l+1,r-1)+(arr[l].second+arr[r].second==2?1:0);
	else dp[l][r]=1e9+1;
//	cout<<l<<" "<<r<<endl;
	for(int i=l;i<r;i++)dp[l][r]=min(dp[l][r],dfs(l,i)+dfs(i+1,r));
	return dp[l][r];
} 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&seq[i]);
	arr[cnt].first=seq[1];
	arr[cnt].second=1;
	for(int i=2;i<=n;i++){
		if(seq[i]!=seq[i-1]){
			arr[++cnt].first=seq[i];
			arr[cnt].second=1;
		}
		else {
			arr[cnt].second++;
		}
	}
	//for(int i=1;i<=cnt;i++)cout<<arr[i].first<<" "<<arr[i].second<<endl;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=cnt;i++)
		if(arr[i].second==1)dp[i][i]=2;
		else dp[i][i]=1;
	printf("%d\n",dfs(1,cnt));
}
