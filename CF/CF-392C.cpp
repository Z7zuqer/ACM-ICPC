#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,m;
LL k;
LL x,y;
LL maxv,minv=1e18,res,mod,A,B;
LL cnt[103][103];
int main(){
	cin>>n>>m>>k>>x>>y;
	LL A=(n*2-2)*m;
	if(n==1)A=m;
	maxv=k/A;
	if(n==1)
		for(int i=1;i<=m;i++)cnt[1][i]=maxv;
	else 
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(i==1||i==n)cnt[i][j]=maxv;
				else cnt[i][j]=2*maxv;
			}
	k%=A;
	if(n==1)
		for(int i=1;i<=k;i++)cnt[1][i]++;
	else {
		for(int i=1;i<n;i++){
			for(int j=1;j<=m;j++){
				if(!k)break;
				cnt[i][j]++;
				k--;
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=1;j<=m;j++){
				if(!k)break;
				cnt[i][j]++;
				k--;
			}
		}
	}
	res=cnt[x][y];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			maxv=max(maxv,cnt[i][j]);
			minv=min(minv,cnt[i][j]);
		}
	cout<<maxv<<" "<<minv<<" "<<res<<endl;
}


