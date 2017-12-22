#include<bits/stdc++.h>
using namespace std;
#define LL long long
int bits[101];
LL dp[101][3];
LL dfs(int len,int is4,int mask){
    if(len==0)return 1;
    if(!mask&&dp[len][is4]>=0)return dp[len][is4];
    LL cnt=0,maxv=(mask?bits[len]:9);
    for(int i=0;i<=maxv;i++){
        if(is4&&i==9)continue;
        cnt+=dfs(len-1,i==4,mask&&i==maxv);
    }
    return mask?cnt:dp[len][is4]=cnt;
}
LL work(LL k){
    int len=0;
    while(k){
        bits[++len]=k%10;
        k/=10;
    }
    return dfs(len,0,1);
}
int main(){
    LL n,m;
    memset(dp,-1,sizeof(dp));
    int t;
    cin>>t;
    int l=work(0);
    while(t--){
        cin>>n;
        cout<<n-work(n)+l<<endl;
    }
}
