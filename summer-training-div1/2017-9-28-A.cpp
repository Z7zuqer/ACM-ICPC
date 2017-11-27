#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=200010;
LL qmin[maxn],qmax[maxn],m,s,a[maxn];
int main(){	
	LL n;
	LL L=-1,R=-1,flg1=0,flg2=0;
    scanf("%lld%lld",&n,&s);
    LL i,j,l=0,ans=0,lm=0,lx=0,rm=0,rx=0;
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]<=s)flg2=1;
        while(lm<rm&&a[qmin[rm-1]]>a[i]) rm--;
        while(lx<rx&&a[qmax[rx-1]]<a[i]) rx--;
        qmin[rm++]=i;
        qmax[rx++]=i;
        while(a[qmax[lx]]-a[qmin[lm]]>s)
            l=(qmin[lm]<qmax[lx]?qmin[lm++]:qmax[lx++]);
        if(l>0&&i-l>ans){
            ans=i-l;
            L=l+1;R=i;
        }
    }
    if(!flg2)return 0*printf("-1\n");
    printf("%lld\n%lld %lld\n",ans,L-1,n-R);
}
