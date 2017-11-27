#include<bits/stdc++.h>
using namespace std;
double dp[30010][1001];
bool mp[30001][1001];
const double x=1.0/3.0;
const double y=1.0/2.0;
int main(){
	int m,k,n;
	scanf("%d%d%d",&m,&k,&n);
	int sta;
	scanf("%d",&sta);
	for(int i=1;i<=k;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		mp[b][a]=1;
	}
	dp[0][sta]=1;
	if(m==1){
		int flg=1;
		for(int i=1;i<=n;i++)
			if(mp[i][1])return 0*printf("0.000000\n");
		return 0*printf("1.000000\n");
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			if(mp[i][1])dp[i][1]=0;else dp[i][1]=dp[i-1][1]*y+dp[i-1][2]*y;
			if(mp[i][2])dp[i][2]=0;else dp[i][2]=dp[i-1][1]*y+dp[i-1][2]*y;
		}
		double ans=0;
		for(int i=1;i<=m;i++)ans+=dp[n][i];
		printf("%.6lf\n",ans);
		return 0;
	} 
	for(int i=1;i<=n;i++){
		if(mp[i][1])dp[i][1]=0;else dp[i][1]=dp[i-1][1]*y+dp[i-1][2]*x;
		if(mp[i][m])dp[i][m]=0;else dp[i][m]=dp[i-1][m]*y+dp[i-1][m-1]*x;
		for(int j=2;j<m;j++)
			if(mp[i][j])dp[i][j]=0;
			else {
				if(fabs(dp[i-1][j-1])>1e-8){
					if(j-1==1)dp[i][j]+=dp[i-1][j-1]*y;
					else dp[i][j]+=dp[i-1][j-1]*x;
				}
				if(fabs(dp[i-1][j+1])>1e-8){
					if(j+1==m)dp[i][j]+=dp[i-1][j+1]*y;
					else dp[i][j]+=dp[i-1][j+1]*x;
				}
				if(fabs(dp[i-1][j])>1e-8)dp[i][j]+=dp[i-1][j]*x;
			}
	}
	double ans=0;
	for(int i=1;i<=m;i++)ans+=dp[n][i];
	printf("%.6lf\n",ans);
}


