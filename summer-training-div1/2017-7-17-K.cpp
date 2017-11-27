#include<bits/stdc++.h>
using namespace std;
int dp[5003][1026];
int main(){
	//freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		int all_sta=1<<k;all_sta-=1;
		memset(dp,-1,sizeof dp);
		string s;
		dp[1][0]=0;dp[1][1]=1;
		for(int i=2;i<=n;i++){
			cin>>s;cin>>s;cin>>s;
			int num;
			if(s[0]=='P'){
				scanf("%d",&num);
				//cout<<num<<endl;
				cin>>s;cin>>s;cin>>s;
				int isbad=(s[0]=='b');cin>>s;
				int pos=i-num-1;//cout<<pos<<endl;
				for(int j=0;j<=all_sta;j++){
					if(dp[i-1][j]==-1)continue;
					if(((j&(1<<pos))?1:0)!=isbad)dp[i][(j*2+1)&all_sta]=max(dp[i][(j*2+1)&all_sta],dp[i-1][j]+1);
					dp[i][(j*2)&all_sta]=max(dp[i][(j*2)&all_sta],dp[i-1][j]);
				}
			}
			else {
				int num_2,isbad,isbad_2;
				cin>>s;scanf("%d",&num);
				int pos=i-num-1;
				cin>>s;cin>>s;cin>>s;
				isbad=(s[0]=='b');
				cin>>s;cin>>s;scanf("%d",&num_2);
				int pos_2=i-num_2-1;
				cin>>s;cin>>s;cin>>s;
				isbad_2=(s[0]=='b'); 
				cin>>s;
				for(int j=0;j<=all_sta;j++){
					if(dp[i-1][j]==-1)continue;
					if((((j&(1<<pos))?1:0)==isbad)||(((j&(1<<pos_2))?1:0)!=isbad_2))dp[i][(j*2+1)&all_sta]=max(dp[i][(j*2+1)&all_sta],dp[i-1][j]+1);
					dp[i][(j*2)&all_sta]=max(dp[i][(j*2)&all_sta],dp[i-1][j]);
				}
			}
		}
		int maxm=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=all_sta;j++)
				maxm=max(maxm,dp[i][j]);
		printf("%d\n",maxm);
	}
}


