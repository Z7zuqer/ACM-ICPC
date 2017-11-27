#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
const int T=1000;
#define LL long long 
int n,d,c,rem,same,q;
int card[2][11],cnt[51];
double dp[T][11][11][11];
LL C[maxn][maxn];
int main(){
    C[0][0]=1;
    for(int i=1;i<=50;++i){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;++j)C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    scanf("%d%d%d",&n,&d,&c);
    for(int i=0;i<=1;i++)
        for(int j=1;j<=c;j++){
            scanf("%d",&card[i][j]);
            cnt[card[i][j]]++;
            if(cnt[card[i][j]]==2)same++;
        }
    rem=c-same;
    q=n-rem*2-same;
    dp[0][rem][rem][same]=1.0;
    for(int i=1;i<T;i++)
    	for(int j=rem;j>=0;j--)
    		for(int k=rem;k>=0;k--)
    			for(int t=same;t>=0;t--){
			        if(n-(j+k+t)<d)continue;
			        for(int j_=rem;j_>=j;j_--)
			        	for(int k_=rem;k_>=k;k_--)
			        		for(int t_=same;t_>=t;t_--){
					            if(j_+k_+t_-j-k-t>d||j_+t_==0||k_+t_==0)continue;
					            dp[i][j][k][t]+=dp[i-1][j_][k_][t_]/C[n][d]*C[j_][j_-j]*C[k_][k_-k]*C[t_][t_-t]*C[n-j_-k_-t_][d-(j_-j+k_-k+t_-t)];
			        }
    			}
    double ans=0;
    for(int i=1;i<T;i++){
    	for(int j=rem;j;j--){
        	ans+=i*dp[i][j][0][0];
            ans+=i*dp[i][0][j][0];     	
        }
		ans+=i*dp[i][0][0][0];
    }
/*
30 5 10 2 3 5 7 11 13 17 19 23 29 20 18 16 14 12 10 8 6 4 2
*/
    printf("%.10lf\n",ans);
}

