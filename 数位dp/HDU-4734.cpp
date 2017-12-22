#include<bits/stdc++.h>
using namespace std;
#define LL long long
int bits[101];
int dp[20][200000],poww[20];
int dfs(int len,int now,int mask){
    if(len==0)return now>=0;
    if(now<0)return 0;
    if(!mask&&dp[len][now]!=-1)return dp[len][now];
    int cnt=0,maxv=(mask?bits[len]:9);
    for(int i=0;i<=maxv;i++)
        cnt+=dfs(len-1,now-poww[len-1]*i,mask&&i==maxv);
    return mask?cnt:dp[len][now]=cnt;
}
int work(int A,int B){
    int len=0;
    int r=0;
    while(A){
        r=r+(poww[len++]*(A%10));
        A/=10;
    }
    len=0;
    while(B){
        bits[++len]=B%10;
        B/=10;
    }
    return dfs(len,r,1);
}
int main(){
    memset(dp,-1,sizeof(dp));
    poww[0]=1;
    for(int i=1;i<=19;i++)poww[i]=poww[i-1]*2;
    int A,B;
    int t,cas=1;
    cin>>t;
    while(t--){
        scanf("%d%d",&A,&B);
        printf("Case #%d: ",cas++);
        cout<<work(A,B)<<endl;
    }
}
