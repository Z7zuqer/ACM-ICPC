#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
struct line{
    double y,l,r;
    int d;
    bool operator<(const line &rhs)const{
        return y<rhs.y;
    }
}A[maxn<<1];
double B[maxn<<1],tr[maxn<<3];
int re=0,cnt[maxn<<3];
void pushup(int t,int l,int r){
    if(cnt[t])tr[t]=B[r+1]-B[l];
    else if(l==r)tr[t]=0;
    else tr[t]=tr[t<<1|1]+tr[t<<1];
}
void update(int t,int l,int r,int L,int R,int v){
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
int sig(double x){
    int l=1,r=re;
    while(l<r){
        int mid=(l+r)>>1;
        if(B[mid]>=x)r=mid;
        else l=mid+1;
    }
    return r;
}
int main(){
    int n,cas=1;
    while(~scanf("%d",&n)&&n){
        re=0;
        memset(tr,0,sizeof(tr));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++){
            double x1,x2,y1,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            A[i]={y1,x1,x2,1};A[i+n]={y2,x1,x2,-1};
            B[++re]=x1;B[++re]=x2;
            //cout<<x1<<" "<<x2<<endl;
        }
        sort(A+1,A+1+n+n);
        sort(B+1,B+1+n+n);
        re=unique(B+1,B+1+n+n)-B-1;
        double ans=0,pre=0;
        for(int i=1;i<=n+n;i++){
            //cout<<tr[1]<<endl;
            ans+=tr[1]*(A[i].y-pre);
            update(1,1,re,sig(A[i].l),sig(A[i].r)-1,A[i].d);
            pre=A[i].y;
        }
        printf("Test case #%d\n",cas++);
        printf("Total explored area: %.2lf\n",ans);
        cout<<endl;
    }
}
