#include <bits/stdc++.h>
using namespace std;
#define INF        (~(1<<31))
typedef long long int LL ;
typedef unsigned long long int uLL ;
const int maxn=1e5+7;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
int trie[maxn*40][3],sum[maxn*40],val[maxn*40],to[maxn*40],cnt,weishu = 30-1;
LL ans,tot,ta,tt;
inline void insert(int x){
    int now = 0;
    for(int i=weishu,bt;i>=0;i--){
        bt = 1-(0==(x&(1<<i)));
        if(!trie[now][bt]) trie[now][bt]=++cnt;
        now = trie[now][bt];
        sum[now]++;
    }
    val[now]=x;
}

inline int query(int x,int pre){
    int now = 0;
    for(int i=weishu,bt;i>=0;i--){
        bt = 1-(0==(x&(1<<i)));
        if(!trie[now][bt]) bt = 1-bt;
        if(now == pre) bt = 1-bt;
        now = trie[now][bt];
    }
    return now;
}

void dfs2(int x,int &pre){
    if(trie[x][0]) dfs2(trie[x][0],pre);
    if(trie[x][1]) dfs2(trie[x][1],pre);

    if(!trie[x][0]&&!trie[x][1]){
        int now = query(val[x],pre);
        if( ta>(val[now]^val[x]))
            ta=(val[now]^val[x]);
    }
}
void dfs(int x){
    if(trie[x][0]) dfs(trie[x][0]);
    if(trie[x][1]) dfs(trie[x][1]);
    if(trie[x][0]&&trie[x][1]){
        ta = INF;
        if(to[trie[x][1]]<to[trie[x][0]])
            dfs2(trie[x][1],x);
        else      dfs2(trie[x][0],x);
        ans+=ta;
    }
}
int dfs1(int x){
    if(!trie[x][0]&&!trie[x][1])
        return to[x]=1;
    if(trie[x][0]) to[x]+=dfs1(trie[x][0]);
    if(trie[x][1]) to[x]+=dfs1(trie[x][1]);
    return to[x];
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        cnt = 0;
        ans = 0ll;
        for(int i=1,x;i<=n;i++){
            x=read();
            insert(x);
        }
        dfs1(0);
        dfs(0);
        printf("%lld\n",ans);
    }
}
