#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int mod=2520;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int bits[101];
int hashr[2550];
LL dp[50][2525][50],poww[20],A[50];
LL dfs(int len,int rmod,int mask,int lcmm){
    if(len==0){
        if(rmod%lcmm==0)return 1;
        return 0;
    }
    if(!mask&&dp[len][rmod][hashr[lcmm]]!=-1)return dp[len][rmod][hashr[lcmm]];
    LL cnt=0,maxv=(mask?bits[len]:9);
    for(int i=0;i<=maxv;i++)
        cnt+=dfs(len-1,(rmod*1LL+i*poww[len-1])%mod,mask&&i==maxv,i==0?lcmm:lcm(lcmm,i));
    return mask?cnt:dp[len][rmod][hashr[lcmm]]=cnt;
}
void init(){
    for(int i=0;i<(1<<9);i++){
        int tmp=1;
        for(int j=1;j<9;j++){
            if(i&(1<<j))tmp=lcm(tmp,j+1);
        }
        hashr[tmp]=1;
    }
    int cnt=1;
    for(int i=0;i<=2520;i++)
        if(hashr[i])
            hashr[i]=cnt,A[cnt++]=i;
}
LL work(LL k){
    if(!k)return 1;
    int len=0;
    while(k){
        bits[++len]=k%10;
        k/=10;
    }
    return dfs(len,0,1,1);
}
int main(){
    init();
    memset(dp,-1,sizeof(dp));
    poww[0]=1;
    for(int i=1;i<=19;i++)poww[i]=poww[i-1]*10;
    LL l,r;
    int t;
    cin>>t;
    while(t--){
        cin>>l>>r;
        cout<<work(r)-work(l-1)<<endl;
    }
}
