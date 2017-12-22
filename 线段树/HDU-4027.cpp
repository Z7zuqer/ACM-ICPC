#include<iostream>
#include<string.h>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define LL long long
const int maxn=100010;
LL tr[maxn<<2];
void pushup(int t){
    tr[t]=tr[t<<1]+tr[t<<1|1];
}
void build(int t,int l,int r){
    if(l==r){
        scanf("%I64d",&tr[t]);
        return ;
    }
    int mid=(l+r)>>1;
    build(t<<1,l,mid);
    build(t<<1|1,mid+1,r);
    pushup(t);
}
void update(int t,int l,int r,int L,int R){
    if(l==r&&l<=R&&l>=L){
        tr[t]=(LL)sqrt(tr[t]);
        return ;
    }
    if(l>=L&&r<=R&&tr[t]==r-l+1)return ;
    int mid=(l+r)>>1;
    if(mid>=L)update(t<<1,l,mid,L,R);
    if(mid<R)update(t<<1|1,mid+1,r,L,R);
    pushup(t);
}
LL query(int t,int l,int r,int L,int R){
    if(l>=L&&r<=R)return tr[t];
    int mid=(l+r)>>1;LL ans=0;
    if(mid>=L)ans+=query(t<<1,l,mid,L,R);
    if(mid<R)ans+=query(t<<1|1,mid+1,r,L,R);
    pushup(t);
    return ans;
}
int main(){
    int n,q,t,cas=1;
    while(scanf("%d",&n)!=EOF){
        memset(tr,0,sizeof(tr));
        build(1,1,n);
        scanf("%d",&q);
        printf("Case #%d:\n",cas++);
        while(q--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            int s=b+c;
            b=min(b,c);
            c=s-b;
            if(a)printf("%I64d\n",query(1,1,n,b,c));
            else update(1,1,n,b,c);
        }
        cout<<endl;
    }
}
