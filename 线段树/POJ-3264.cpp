#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
const int maxn=50010;
int minv[maxn<<2],maxv[maxn<<2];
void pushup1(int t){
    minv[t]=min(minv[t<<1],minv[t<<1|1]);
}
void pushup2(int t){
    maxv[t]=max(maxv[t<<1],maxv[t<<1|1]);
}
void build(int t,int l,int r){
    if(l==r){
        scanf("%d",&minv[t]);
        maxv[t]=minv[t];
        return ;
    }
    int mid=(l+r)>>1;
    build(t<<1,l,mid);
    build(t<<1|1,mid+1,r);
    pushup1(t);
    pushup2(t);
}
int query1(int t,int l,int r,int L,int R){
    if(l>=L&&r<=R)return minv[t];
    int mid=(l+r)>>1,ans=1e9+1;
    if(mid>=L)ans=min(ans,query1(t<<1,l,mid,L,R));
    if(mid<R)ans=min(ans,query1(t<<1|1,mid+1,r,L,R));
    pushup1(t);
    pushup2(t);
    return ans;
}
int query2(int t,int l,int r,int L,int R){
    if(l>=L&&r<=R)return maxv[t];
    int mid=(l+r)>>1,ans=0;
    if(mid>=L)ans=max(ans,query2(t<<1,l,mid,L,R));
    if(mid<R)ans=max(ans,query2(t<<1|1,mid+1,r,L,R));
    pushup1(t);
    pushup2(t);
    return ans;
}
int main(){
    int n,q,t,cas=1;
    while(~scanf("%d%d",&n,&q)){
        build(1,1,n);
        //printf("Case %d:\n",cas++);
        while(q--){
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",query2(1,1,n,a,b)-query1(1,1,n,a,b));
        }
    }
}
