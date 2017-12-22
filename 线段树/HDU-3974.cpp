#include<iostream>
#include<string.h>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=50010;
#define LL long long
int cnt=1,son[maxn],dfn[maxn],fa[maxn];
LL lazy[maxn<<2],tr[maxn<<2];
vector<int>v[maxn];
void dfs(int u,int pre){
    dfn[u]=cnt++;
    son[u]=dfn[u];
    for(int i=0;i<v[u].size();i++){
        dfs(v[u][i],u);
        son[u]=max(son[u],son[v[u][i]]);
    }
}
void pushdown(int t){
    if(lazy[t]){
        lazy[t<<1]=lazy[t];
        tr[t<<1]=lazy[t];
        lazy[t<<1|1]=lazy[t];
        tr[t<<1|1]=lazy[t];
        lazy[t]=0;
    }
}
void update(int t,int l,int r,int L,int R,LL v){
    if(l>=L&&r<=R){
        tr[t]=v;
        lazy[t]=v;
        return ;
    }
    pushdown(t);
    int mid=(l+r)>>1;
    if(mid>=L)update(t<<1,l,mid,L,R,v);
    if(mid<R)update(t<<1|1,mid+1,r,L,R,v);
}
LL query(int t,int l,int r,int x){
    if(l==r&&l==x)return tr[t];
    int mid=(l+r)>>1;
    pushdown(t);
    if(x<=mid)return query(t<<1,l,mid,x);
    else return query(t<<1|1,mid+1,r,x);
}
int main(){
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        cnt=1;
        int n;
        scanf("%d",&n);
        memset(lazy,0,sizeof(lazy));
        memset(fa,0,sizeof(fa));
        memset(tr,0,sizeof(tr));
        for(int i=1;i<maxn;i++)v[i].clear();
        for(int i=1;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            v[b].push_back(a);
            fa[a]++;
        }
        for(int i=1;i<=n;i++){
            if(!fa[i]){
                dfs(i,-1);
                break;
            }
        }
        int q;
        char s[2];
        scanf("%d",&q);
        printf("Case #%d:\n",cas++);
        while(q--){
            scanf("%s",s);
            if(s[0]=='C'){
                int a;
                scanf("%d",&a);
                LL ans=query(1,1,n,dfn[a]);
                printf("%lld\n",ans==0?-1:ans);
            }
            if(s[0]=='T'){
                int a;
                LL b;
                scanf("%d%lld",&a,&b);
                update(1,1,n,dfn[a],son[a],b);
                //cout<<dfn[a]<<"  "<<son[a]<<endl;
            }
        }
    }

}
