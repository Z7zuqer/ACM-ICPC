#include<bits/stdc++.h>
using namespace std;

const int MOD = 2147483647;
int n,pm[2017],dp[2][2017][2017];

int main(){
    cin >> n;
    for(int i = 0;i <= n;++i) scanf("%d",&pm[i]);
    dp[1][pm[0]][pm[1]] = 1;
    for(int i = 2;i <= n;++i){
        int t = pm[i];
        for(int j = 1;j < t;++j)
            for(int k = j + 1;k <= n + 1;++k)
                dp[i&1][j][t] += dp[(i-1)&1][j][k];

        for(int j = t + 1;j <= n + 1;++j)
            for(int k = j - 1;k >= 1;--k)
                dp[i&1][t][j] += dp[(i-1)&1][k][j];

        memset(dp[(i-1)&1],0,sizeof dp[(i-1)&1]);

//        printf("//t = %d\n",t);
//        for(int j = 1;j <= n;++j)
//            for(int k = j + 1;k <= n + 1;++k)
//                if(dp[i&1][j][k])printf("//dp[%d][%d][%d] = %d\n",i,j,k,dp[i&1][j][k]);

    }
    int ans = 0;
    for(int i = 1;i <= n;++i)
        for(int j = i + 1;j <= n + 1;++j)
            ans += dp[n&1][i][j];
    if(ans

