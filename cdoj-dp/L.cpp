#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int mod=1e9+7;
LL dp[2][1<<11],cur;
void update(LL &a,LL b){
	a+=b;
	if(a>mod)a-=mod;
}
LL cal(int n,int m){
    if(n==m&&n%2==1)return 0;
    if(n<m) swap(n,m);
    memset(dp[0],0,sizeof(dp[0]));
    dp[cur=0][(1<<m)-1]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cur^=1;
            memset(dp[cur],0,sizeof(dp[cur]));
            int r=(1<<m)-1;
            for(int s=0;s<(1<<m);s++){
                LL v=dp[cur^1][s];
                if((s&(1<<m-1))==0)             
                    update(dp[cur][(s<<1)+1],v);
                else{
                    update(dp[cur][(s<<1)&r],v);
                    if(j>1&&(s&1)==0 )          
                        update(dp[cur][((s<<1)+3)&r],v);
                }
            }
        }
    }
    return dp[cur][(1<<m)-1];
}

int main(){
	int n, m;
	scanf("%d%d",&n,&m);
    printf("%lld\n",cal(n,m));
}

