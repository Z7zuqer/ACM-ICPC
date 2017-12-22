#include<iostream>
#include<string.h>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10000;
struct line{
    int top,l,r,cnt;
    bool operator<(const line &a)const{
        return top<a.top;
    }
}A[maxn<<1],B[maxn<<1];
int tr[maxn<<3],cnt[maxn<<3];
void pushup(int t,int l,int r){
    if(cnt[t])tr[t]=r-l+1;
    else if(l==r)tr[t]=0;
    else tr[t]=tr[t<<1]+tr[t<<1|1];
}
void update(int t,int l,int r,int L,int R,int v){
    //cout<<l<<" "<<r<<endl;
    if(l>=L&&r<=R){
        cnt[t]+=v;
        pushup(t,l,r);
        return ;
    }
    int mid=(l+r)>>1;
    if(mid>=L)update(t<<1,l,mid,L,R,v);
    if(mid<R)update(t<<1|1,mid+1,r,L,R,v);
    pushup(t,l,r);
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(tr,0,sizeof(tr));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++){
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            A[i]={x1+maxn+1,y1+maxn+1,y2+maxn+1,1};A[i+n]={x2+maxn+1,y1+maxn+1,y2+maxn+1,-1};
            B[i]={y1+maxn+1,x1+maxn+1,x2+maxn+1,1};B[i+n]={y2+maxn+1,x1+maxn+1,x2+maxn+1,-1};
        }
        sort(A+1,A+1+n+n);
        sort(B+1,B+1+n+n);
        int pre=0,ans=0;
        for(int i=1;i<=n+n;i++){
            update(1,1,maxn*2+3,A[i].l,A[i].r-1,A[i].cnt);
            ans+=abs(pre-tr[1]);
            pre=tr[1];
        }
        //cout<<"dsadsada"<<endl;
        memset(tr,0,sizeof(tr));
        memset(cnt,0,sizeof(cnt));
        pre=0;
        for(int i=1;i<=n+n;i++){
            update(1,1,maxn*2+3,B[i].l,B[i].r-1,B[i].cnt);
            ans+=abs(pre-tr[1]);
            pre=tr[1];
        }
        printf("%d\n",ans);
    }
}
