#include<bits/stdc++.h>
using namespace std;
int len,cntw[1000100],cntc[1000100];
char cards[1000100];
double dp[2][1000100];
int main(){
    //freopen("foreign.in","r",stdin);
    //freopen("foreign.out","w",stdout);
    scanf("%s",cards);
    len = strlen(cards);
    if(cards[0]=='C')dp[0][0]=1,dp[1][0]=0;
    else dp[0][0]=0,dp[1][0]=1;
    for(int i=1;i<len;i++){
    	if(cards[i]=='W'){
    		dp[0][i]=dp[0][i-1]*(1.0-(1.0/(len-i+1)));
    		dp[1][i]=1-dp[0][i];
    	}
    	if(cards[i]=='C'){
    		dp[1][i]=dp[1][i-1]*(1.0-(1.0/(len-i+1)));
    		dp[0][i]=1-dp[1][i];
    	}
    }
    double ans=0;
	for(int i=0;i<len;i++)
		 if(cards[i]=='W')ans+=dp[0][i];
		 else ans+=dp[1][i];
	printf("%.12lf",ans);
    return 0;
}
