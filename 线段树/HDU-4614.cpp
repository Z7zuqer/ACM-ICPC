#include<iostream>
#include<string.h>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=50010;
int tr[maxn<<2],lazy[maxn<<2];
void pushdown(int t,int l,int r){
    if(lazy[t]==0){
        lazy[t<<1]=0;
        tr[t<<1]=0;
        lazy[t<<1|1]=0;
        tr[t<<1|1]=0;
        lazy[t]=-1;
    }
    else if(lazy[t]==1){
        int mid=(l+r)>>1;
        lazy[t<<1]=1;
        tr[t<<1]=mid-l+1;
        lazy[t<<1|1]=1;
        tr[t<<1|1]=r-mid;
        lazy[t]=-1;
    }
}
void pushup(int t){
    tr[t]=tr[t<<1]+tr[t<<1|1];
}
void update(int t,int l,int r,int L,int R,int v){
    //cout<<l<<" "<<r<<endl;
    if(l>=L&&r<=R){
        tr[t]=v*(r-l+1);
        lazy[t]=v;
        return ;
    }
    pushdown(t,l,r);
    int mid=(l+r)>>1;
    if(mid>=L)update(t<<1,l,mid,L,R,v);
    if(mid<R)update(t<<1|1,mid+1,r,L,R,v);
    pushup(t);
}
int query(int t,int l,int r,int L,int R){
    if(l>=L&&r<=R)return tr[t];
    pushdown(t,l,r);
    int mid=(l+r)>>1,ans=0;
    if(mid>=L)ans+=query(t<<1,l,mid,L,R);
    if(mid<R)ans+=query(t<<1|1,mid+1,r,L,R);
    pushup(t);
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        memset(lazy,-1,sizeof(lazy));
        memset(tr,0,sizeof(tr));
        scanf("%d%d",&n,&q);
        while(q--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(a==1){
                int l=b+1,r=n,ll=l,rr=r;
                int rem=(n-b-1+1-query(1,1,n,b+1,n));
                if(rem<=0){
                    printf("Can not put any one.\n");
                    continue;
                }
                if(rem<c)swap(rem,c);
                while(l<r){
                    int mid=(l+r)>>1;
                    if(mid-b-1+1-query(1,1,n,b+1,mid)>0){
                        ll=mid;
                        r=mid;
                    }
                    else l=mid+1;
                }
                l=b+1,r=n;
                while(l<r){
                    //if(b==4&&c==4)cout<<l<<" "<<r<<endl;
                    int mid=(l+r)>>1;
                    if(mid-ll+1-query(1,1,n,ll,mid)>=c){
                        rr=mid;
                        r=mid;
                    }
                    else l=mid+1;
                }
                printf("%d %d\n",ll-1,rr-1);
                update(1,1,n,ll,rr,1);
            }
            else {
                printf("%d\n",query(1,1,n,b+1,c+1));
                update(1,1,n,b+1,c+1,0);
            }
        }
        cout<<endl;
    }
}
