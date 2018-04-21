#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,k,c[64][64],p,q,d[64],r,w,s,t,ans;
int main()
{
    c[0][0]=1;
    for (int i=1;i<64;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
   scanf("%d",&query);
   while (query--)
    {
       scanf("%lld%lld",&n,&k); r=0; p=q=0;
       printf("Case #%d: ",++kase);
       while (n) {
           d[r++]=n&1;
           n>>=1;
        }
       for (int i=0;i<r-1;i++) if (d[i]) p++; else q++;
       s=p; t=q; w=1;
       for (int i=r-2;i>=1;i--)
            if (d[i]) w+=c[p+q-1][p],p--; else q--;
       w+=k;
       if (w>c[s+t][s]) printf("IMPOSSIBLE\n");
       else {
           ans=1ll<<(r-1);
           for (int i=r-2;i>=0;i--)
               if (t==0||c[s+t-1][s]<w) w-=c[s+t-1][s],s--,ans+=(1ll<<i); else t--;
           cout << ans << endl;
		}
	}
	return 0;
}
