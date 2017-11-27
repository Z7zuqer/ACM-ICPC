#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,bits[50],LEN=0;
LL dp[50][33][2],DP[50][33][2];
LL dfs_1(int pos,int pre,int flg,int mask){
	if(pos<0)return flg;
    if(!mask&&dp[pos][pre][flg]!=-1)return dp[pos][pre][flg];
	LL res=0,maxv=mask?bits[pos]:9;
    if(flg==0)
        for(int i=0;i<=min(pre*1LL,maxv);i++)
            if(i==0)res+=dfs_1(pos-1,10,0,mask&&(i==maxv));
            else res+=dfs_1(pos-1,i,1,mask&&(i==maxv));
    else
        for(int i=0;i<=min(maxv,pre*1LL);i++)
            res+=dfs_1(pos-1,i,flg,mask&&(i==maxv));
    if(!mask)dp[pos][pre][flg]=res;
    return res;
}
LL dfs_2(int pos,int pre,int flg,int mask){
	if(pos<0)return flg;
    if(!mask&&DP[pos][pre][flg]!=-1)return DP[pos][pre][flg];
    LL res=0,maxv=mask?bits[pos]:9;
    for(int i=pre;i<=maxv;i++)res+=dfs_2(pos-1,i,flg||i,mask&&(i==maxv));
    if(!mask)DP[pos][pre][flg]=res;
    return res;
}
LL mins(LL k){
    if(k==0)return 0;
    LL ans=(LEN-1)*9LL+bits[LEN-1];
    LL res=0,TLEN=0;
    while(TLEN<LEN)res=res*10+bits[LEN-1],TLEN++;
    if(res>k)ans--;
    return ans;
}
LL work(LL k){
	LEN=0;
	LL res=k;
    while(k){
        bits[LEN++]=k%10;
        k/=10;
    }
    return dfs_1(LEN-1,10,0,1)+dfs_2(LEN-1,0,0,1)-mins(res);
}
int main(){ 
    int m;
    scanf("%d",&m);
    memset(dp,-1,sizeof dp);
    memset(DP,-1,sizeof DP);
    while(m--){
        LL l,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",work(r)-work(l-1));
    }
    return 0;
}
