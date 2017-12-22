#include<bits/stdc++.h>
using namespace std;
int bits[11];
int dp[11][3];
int dfs(int len,int is6,int mask){
    if(len==0)return 1;
    if(!mask&&dp[len][is6]>=0)return dp[len][is6];
    int cnt=0,maxv=(mask?bits[len]:9);
    for(int i=0;i<=maxv;i++){
        if(i==4||(i==2&&is6))continue;
        cnt+=dfs(len-1,i==6,mask&&i==maxv);
    }
    return mask?cnt:dp[len][is6]=cnt;
}
int work(int k){
    int len=0;
    while(k){
        bits[++len]=k%10;
        k/=10;
    }
    return dfs(len,0,1);
}
int main(){
    int n,m;
    memset(dp,-1,sizeof(dp));
    while(~scanf("%d%d",&n,&m)&&(n||m)){
        cout<<work(m)-work(n-1)<<endl;
    }
}
