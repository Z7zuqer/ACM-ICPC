#include<iostream>
#include<string.h>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=50010;
struct {
    int l,r;
    int ls,rs,ms;
}tr[maxn<<2];
void pushup(int t){
    tr[t].ls=tr[t<<1].ls;
    tr[t].rs=tr[t<<1|1].rs;
    tr[t].ms=max(tr[t<<1].ms,max(tr[t<<1|1].ms,tr[t<<1].rs+tr[t<<1|1].ls));
    if(tr[t].ls==tr[t<<1].r-tr[t<<1].l+1)tr[t].ls+=tr[t<<1|1].ls;
    if(tr[t].rs==tr[t<<1|1].r-tr[t<<1|1].l+1)tr[t].rs+=tr[t<<1].rs;
}
void build(int t,int l,int r){
    tr[t].l=l;tr[t].r=r;
    if(l==r){
        tr[t].ls=tr[t].rs=tr[t].ms=1;
        return ;
    }
    int mid=(l+r)>>1;
    build(t<<1,l,mid);
    build(t<<1|1,mid+1,r);
    pushup(t);
}
void update(int t,int l,int r,int x,int v){
    if(l==r&&x==l){
        tr[t].ls=tr[t].rs=tr[t].ms=v;
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid)update(t<<1,l,mid,x,v);
    if(x>mid)update(t<<1|1,mid+1,r,x,v);
    pushup(t);
}
int query(int t,int l,int r,int x){
    //cout<<tr[t].l<<" "<<l<<endl;
    if(tr[t].l==tr[t].r||tr[t].r-tr[t].l+1==tr[t].ms||tr[t].ms==0)return tr[t].ms;
    int mid=(l+r)>>1;
    if(x<=mid){
        if(x>=tr[t<<1].r-tr[t<<1].rs+1)return query(t<<1,l,mid,x)+query(t<<1|1,mid+1,r,mid+1);
        return query(t<<1,l,mid,x);
    }
    else{
        if(x<=tr[t<<1|1].l+tr[t<<1|1].ls-1)return query(t<<1|1,mid+1,r,x)+query(t<<1,l,mid,mid);
        return query(t<<1|1,mid+1,r,x);
    }
}
int st[51010],top;
int main(){
    int n,q,t,cas=1;
    char s[3];
    while(scanf("%d%d",&n,&q)!=EOF){
        top=0;
        memset(tr,0,sizeof(tr));
        build(1,1,n);
        //printf("Case #%d:\n",cas++);
        while(q--){
            int a;
            scanf("%s",s);
            if(s[0]=='Q'){
                scanf("%d",&a);
                printf("%d\n",query(1,1,n,a));
            }
            if(s[0]=='D'){
                scanf("%d",&a);
                update(1,1,n,a,0),st[++top]=a;
            }
            if(s[0]=='R'){
                update(1,1,n,st[top],1);
                top--;
            }
        }
    }
}
