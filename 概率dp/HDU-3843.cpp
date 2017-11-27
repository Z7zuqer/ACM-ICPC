#include<bits/stdc++.h>
using namespace std;
double mp[1010][1010][4];
double dp[1010][1010];
int main(){
	int r,c;
	while(scanf("%d%d",&r,&c)!=EOF){
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				for(int k=0;k<3;k++)
					scanf("%lf",&mp[i][j][k]);
		//cout<<"daSA"<<endl;
		memset(dp,0,sizeof dp); 
		for(int i=r;i>=1;i--)
			for(int j=c;j>=1;j--){
				if(i==r&&j==c)continue;
				if(mp[i][j][0]==1)continue;
				dp[i][j]=(mp[i][j][1]*dp[i][j+1]+mp[i][j][2]*dp[i+1][j]+2)/(1-mp[i][j][0]);
			}
		printf("%.3lf\n",dp[1][1]);
	}
}


