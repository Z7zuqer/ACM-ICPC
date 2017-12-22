#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
const int maxn=100010;
int tr[maxn<<2],lazy[maxn<<2];
void pushdown(int t){
    if(lazy[t]){
        tr[t<<1]=lazy[t];
        lazy[t<<1]=lazy[t];
        tr[t<<1|1]=lazy[t];
        lazy[t<<1|1]=lazy[t];
        lazy[t]=0;
    }
}
void pushup(int t){
    if(tr[t<<1]==tr[t<<1|1])tr[t]=tr[t<<1];
    else tr[t]=-1;
}
void build(int t,int l,int r){
    if(l==r){
        tr[t]=1;
        return ;
    }
    int mid=(l+r)>>1;
    build(t<<1,l,mid);
    build(t<<1|1,mid+1,r);
}
void update(int t,int l,int r,int L,int R,int v){
    if(l>=L&&r<=R){
        tr[t]=v;
        lazy[t]=v;
        return ;
    }
    pushdown(t);
    int mid=(l+r)>>1;
    if(mid>=L)update(t<<1,l,mid,L,R,v);
    if(mid<R)update(t<<1|1,mid+1,r,L,R,v);
    pushup(t);
}
int query(int t,int l,int r,int L,int R){
    //cout<<l<<" "<<r<<" "<<tr[t]<<endl;
    if(l>=L&&r<=R&&tr[t]>0)return tr[t]*(r-l+1);
    if(l>=r)return 0;
    int mid=(l+r)>>1,ans=0;
    pushdown(t);
    if(mid>=L)ans+=query(t<<1,l,mid,L,R);
    if(mid<R)ans+=query(t<<1|1,mid+1,r,L,R);
    pushup(t);
    return ans;
}
int main(){
    //int t,cas=1;
    //cin>>t;
    char s[5];
    int n,q,t,cas=1;
    cin>>t;
    while(t--){
        scanf("%d%d",&n,&q);
        build(1,1,n);
        //memset(tr,0,sizeof(tr));
        memset(lazy,0,sizeof(lazy));
        //build(1,1,n);
        //printf("Case %d:\n",cas++);
        while(q--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            update(1,1,n,a,b,c);
        }
        printf("Case %d: The total value of the hook is %d.\n",cas++,query(1,1,n,1,n));
    }
}
