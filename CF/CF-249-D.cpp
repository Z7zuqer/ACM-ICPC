#include<bits/stdc++.h>
using namespace std;
#define LL long long
char mp[410][410];
LL dp[410][410];
LL sumx[410][410],sumy[410][410];
LL sxum[410][410],syum[410][410];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			sumx[i][j]=sumx[i-1][j]+(mp[i][j]=='1'),sumy[i][j]=sumy[i][j-1]+(mp[i][j]=='1');
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			sxum[i][j]=sxum[i-1][j-1]+(mp[i][j]=='1'),syum[i][j]=syum[i-1][j+1]+(mp[i][j]=='1');
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='1')continue;
			for(int k=1;k+i<=n&&k+j<=m;k++){//shunshizhen
				if(mp[i][j+k]=='1'||mp[i+k][j]=='1')break;
				if(syum[i+k][j]-syum[i-1][j+k+1]>=1)continue;
				dp[i][j]++;
			}
			for(int k=1;i+k<=n&&j+k<=m&&j-k>=1;k++){
				if(mp[i+k][j-k]=='1'||mp[i+k][j+k]=='1')break;
				if(sumy[i+k][j+k]-sumy[i+k][j-k-1]>=1)continue;
				dp[i][j]++;
			}
			for(int k=1;i+k<=n&&j-k>=1;k++){
				if(mp[i+k][j]=='1'||mp[i][j-k]=='1')break;
				if(sxum[i+k][j]-sxum[i-1][j-k-1]>=1)continue;
				dp[i][j]++;
			}
			for(int k=1;i-k>=1&&j-k>=1&&i+k<=n;k++){
				if(mp[i-k][j-k]=='1'||mp[i+k][j-k]=='1')break;
				if(sumx[i+k][j-k]-sumx[i-k-1][j-k]>=1)continue;
				dp[i][j]++;
			}
			for(int k=1;i-k>=1&&j-k>=1;k++){
				if(mp[i-k][j]=='1'||mp[i][j-k]=='1')break;
				if(syum[i][j-k]-syum[i-k-1][j+1]>=1)continue;
				dp[i][j]++;
			}
			for(int k=1;i-k>=1&&j-k>=1&&j+k<=m;k++){
				if(mp[i-k][j-k]=='1'||mp[i-k][j+k]=='1')break;
				if(sumy[i-k][j+k]-sumy[i-k][j-k-1]>=1)continue;
				dp[i][j]++;
			}
			for(int k=1;i-k>=1&&j+k<=m;k++){
				if(mp[i-k][j]=='1'||mp[i][j+k]=='1')break;
				if(sxum[i][j+k]-sxum[i-k-1][j-1]>=1)continue;
				dp[i][j]++;
			}
			for(int k=1;j+k<=m&&i-k>=1&&i+k<=n;k++){
				if(mp[i-k][j+k]=='1'||mp[i+k][j+k]=='1')break;
				if(sumx[i+k][j+k]-sumx[i-k-1][j+k]>=1)continue;
				dp[i][j]++;
			}
		}
	}
	LL ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans+=dp[i][j];
	cout<<ans<<endl;
}


