#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define LL long long
LL dp[2010][2010];
vector<int>v[2010];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<2010;i++){
		for(int j=1;j*j<=i;j++){
			if(j*j==i)v[i].push_back(j);
			else if(i%j==0){
				v[i].push_back(j);
				v[i].push_back(i/j);
			}
		}
	}
	for(int i=0;i<=n;i++)dp[i][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=2;j<=k;j++){
			for(int u=0;u<v[i].size();u++){
				dp[i][j]=(dp[i][j]+dp[v[i][u]][j-1])%mod;
			}
		}
	}
	LL ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+dp[i][k])%mod;
	}
	cout<<ans<<endl;
}


