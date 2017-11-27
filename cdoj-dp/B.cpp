#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<23;
int mp[23][23][23],dp[maxn];
int vis[22],po[24];
inline void scan(int &x){
	char c;
    do c=getchar(); while (c<'0'||c>'9');
    x=c-'0';
    while ('0'<=(c=getchar())&&c<='9') x=x*10+c-'0';
}
int main(){
	int n;
	scan(n);
	int sum=n*(n-1)*(n-2)/6,a,b,c,d;
	for(int i=0;i<sum;i++){
		scan(a);scan(b);scan(c);scan(d);
		mp[a][b][c]=d;
	}
	for(int i=0;i<n;i++)po[i]=1<<i;
	int cnt=(1<<n),maxv=0;
	for(int sta=0;sta<cnt;sta++){
		int r=0;vector<int>v;
		for(int i=1;i<=n;i++){
			vis[i-1]=sta&po[i-1];
			if(vis[i-1]==0)v.push_back(i),r++;
		}
		if(!r)continue;
		if(r%3!=0)continue;
		for(int i=0;i<r-2;i++)
			for(int j=i+1;j<r-1;j++)
				for(int k=j+1;k<r;k++){
					int end=sta|po[v[k]-1]|po[v[j]-1]|po[v[i]-1],val=mp[v[i]][v[j]][v[k]];
					if(dp[end]<dp[sta]+val)dp[end]=dp[sta]+val;
				}
	}	
	for(int i=0;i<cnt;i++)if(maxv<dp[i])maxv=dp[i];	
	printf("%d\n",maxv);
}


