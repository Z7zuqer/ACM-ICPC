#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
#define LL long long
const int maxn=100000;
LL tr[maxn<<2],lazy[maxn<<2];
void pushdown(int t,int l,int r){
    if(lazy[t]){
        int mid=(l+r)>>1;
        tr[t<<1]+=lazy[t]*(mid-l+1);
        lazy[t<<1]+=lazy[t];
        tr[t<<1|1]+=lazy[t]*(r-mid-1+1);
        lazy[t<<1|1]+=lazy[t];
        lazy[t]=0;
    }
}
void pushup(int t){
    tr[t]=tr[t<<1|1]+tr[t<<1];
}
void build(int t,int l,int r){
    if(l==r){
        scanf("%lld",&tr[t]);
        return ;
    }
    int mid=(l+r)>>1;
    build(t<<1,l,mid);
    build(t<<1|1,mid+1,r);
    pushup(t);
}
void update(int t,int l,int r,int L,int R,LL v){
    if(l>=L&&r<=R){
        tr[t]+=(r-l+1)*v;
        lazy[t]+=v;
        return ;
    }
    pushdown(t,l,r);
    int mid=(l+r)>>1;
    if(mid>=L)update(t<<1,l,mid,L,R,v);
    if(mid<R)update(t<<1|1,mid+1,r,L,R,v);
    pushup(t);
}
LL query(int t,int l,int r,int L,int R){
    if(l>=L&&r<=R)return tr[t];
    int mid=(l+r)>>1;LL ans=0;
    pushdown(t,l,r);
    if(mid>=L)ans+=query(t<<1,l,mid,L,R);
    if(mid<R)ans+=query(t<<1|1,mid+1,r,L,R);
    pushup(t);
    return ans;
}
int main(){
    //int t,cas=1;
    //cin>>t;
    char s[5];
    int n,q;
    while(~scanf("%d%d",&n,&q)){
        memset(tr,0,sizeof(tr));
        memset(lazy,0,sizeof(lazy));
        build(1,1,n);
        //printf("Case %d:\n",cas++);
        while(q--){
            scanf("%s",s);
            if(s[0]=='Q'){
                int a,b;
                scanf("%d%d",&a,&b);
                printf("%lld\n",query(1,1,n,a,b));
            }
            else {
                int a,b;
                LL c;
                scanf("%d%d%lld",&a,&b,&c);
                update(1,1,n,a,b,c);
            }
        }
    }
}
