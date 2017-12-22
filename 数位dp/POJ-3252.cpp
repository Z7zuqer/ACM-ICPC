#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
#define LL long long
int bits[100];
LL dp[100][50][50],poww[20];
LL dfs(int len,int now0,int now1,int is0,int mask){
    if(len==0)return now0>=now1;
    if(!mask&&dp[len][now0][now1]!=-1)return dp[len][now0][now1];
    LL cnt=0,maxv=(mask?bits[len]:1);
    for(int i=0;i<=maxv;i++)
        if(is0&&i==0)cnt+=dfs(len-1,0,0,1,mask&&i==maxv);
        else cnt+=dfs(len-1,now0+(i==0),now1+(i==1),is0&&i==0,mask&&i==maxv);
    return mask?cnt:dp[len][now0][now1]=cnt;
}
LL work(LL k){
    int len=0;
    while(k){
        bits[++len]=k%2;
        k/=2;
    }
    return dfs(len,0,0,1,1);
}
int main(){
    memset(dp,-1,sizeof(dp));
    LL A,B;
    while(cin>>A>>B){
        memset(dp,-1,sizeof(dp));
        cout<<work(B)-work(A-1)<<endl;
    }
}
