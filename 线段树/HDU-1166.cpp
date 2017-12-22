#include<bits/stdc++.h>
using namespace std;
const int maxn=50010;
int tr[maxn<<2];
void pushup(int t){
    tr[t]=tr[t<<1]+tr[t<<1|1];
}
void build(int t,int l,int r){
    if(l==r){
        scanf("%d",&tr[t]);
        return ;
    }
    int mid=(l+r)>>1;
    build(t<<1,l,mid);
    build(t<<1|1,mid+1,r);
    pushup(t);
}
void update(int t,int l,int r,int x,int v){
    if(l==r&&l==x){
        tr[t]+=v;
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid)update(t<<1,l,mid,x,v);
    else update(t<<1|1,mid+1,r,x,v);
    pushup(t);
}
int query(int t,int l,int r,int L,int R){
    if(l>=L&&r<=R)return tr[t];
    int mid=(l+r)>>1,ans=0;
    if(mid>=L)ans+=query(t<<1,l,mid,L,R);
    if(mid<R)ans+=query(t<<1|1,mid+1,r,L,R);
    return ans;
}
int main(){
    int t,cas=1;
    cin>>t;
    char s[5];
    while(t--){
        int n;
        scanf("%d",&n);
        build(1,1,n);
        printf("Case %d:\n",cas++);
        while(1){
            scanf("%s",s);
            if(s[0]=='Q'){
                int a,b;
                scanf("%d%d",&a,&b);
                printf("%d\n",query(1,1,n,a,b));
            }
            else if(s[0]=='A'){
                int a,b;
                scanf("%d%d",&a,&b);
                update(1,1,n,a,b);
            }
            else if(s[0]=='S'){
                int a,b;
                scanf("%d%d",&a,&b);
                update(1,1,n,a,-1*b);
            }
            else break;
        }
    }
}
