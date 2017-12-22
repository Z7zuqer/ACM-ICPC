#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int mod=13;
int bits[101];
LL dp[50][15][3][3],poww[20];
LL dfs(int len,int rmod,int mask,int is1,int flg){
    if(len==0){
        if(rmod==0&&flg)return 1;
        return 0;
    }
    if(!mask&&dp[len][rmod][is1][flg]!=-1)return dp[len][rmod][is1][flg];
    LL cnt=0,maxv=(mask?bits[len]:9);
    for(int i=0;i<=maxv;i++)
        cnt+=dfs(len-1,(rmod*1LL+i*poww[len-1])%mod,mask&&i==maxv,i==1,(is1&&i==3)||flg);
    return mask?cnt:dp[len][rmod][is1][flg]=cnt;
}
LL work(LL k){
    int len=0;
    while(k){
        bits[++len]=k%10;
        k/=10;
    }
    return dfs(len,0,1,0,0);
}
int main(){
    memset(dp,-1,sizeof(dp));
    poww[0]=1;
    for(int i=1;i<=19;i++)poww[i]=poww[i-1]*10%mod;
    LL n;
    while(scanf("%lld",&n)!=EOF){
        cout<<work(n)<<endl;
    }
}
