#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL mod=1e9+7;
int bits[50];
LL dp[30][200000],poww[20];
int check(int x){
    for(int i=0;i<=9;i++){
        int r=x%3;
        if(r==1&&i%2==1)return 0;//1 odd 2 even
        if(r==2&&i%2==0)return 0;
        x/=3;
    }
    return 1;
}
int change(int x,int wh){
    int k[15];
    for(int i=0;i<=9;i++){
        k[i]=x%3;
        x/=3;
    }
    if(k[wh]==1)k[wh]=2;
    else if(k[wh]==2)k[wh]=1;
    else k[wh]=1;
    int tmp=0;
    for(int i=9;i>=0;i--){
        tmp=tmp*3+k[i];
    }
    return tmp;
}
LL dfs(int len,int now,int mask,int is0){
    if(len==0){
        if(!is0&&check(now))return 1;
        return 0;
    }
    if(!mask&&dp[len][now]!=-1)return dp[len][now];
    LL cnt=0,maxv=(mask?bits[len]:9);
    for(int i=0;i<=maxv;i++){
        if(is0&&i==0)cnt+=dfs(len-1,0,mask&&i==maxv,1);
        else if(is0)cnt+=dfs(len-1,change(0,i),mask&&i==maxv,0);
        else cnt+=dfs(len-1,change(now,i),mask&&i==maxv,is0&&i==0);
    }
    return mask?cnt:dp[len][now]=cnt;
}
LL work(LL k){
    int len=0;
    while(k){
        bits[++len]=k%10;
        k/=10;
    }
    return dfs(len,0,1,1);
}
int main(){
    memset(dp,-1,sizeof(dp));
    LL A,B;
    int t,cas=1;
    cin>>t;
    while(t--){
        cin>>A>>B;
        cout<<work(B)-work(A-1)<<endl;
    }
}
