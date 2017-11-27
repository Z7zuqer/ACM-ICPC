#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
char s[2];
int A[maxn][maxn],up[maxn][maxn],let[maxn][maxn],rigt[maxn][maxn];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%s",s);
				if(s[0]=='R')A[i][j]=1;
				else A[i][j]=0;
			}
		}
		int ans=0;
		for(int i=0;i<n;i++){
			int lo=-1;
			for(int j=0;j<m;j++){
				if(A[i][j])up[i][j]=let[i][j]=0,lo=j;
				else {
					let[i][j]=i==0?lo+1:max(let[i-1][j],lo+1);
					up[i][j]=i==0?1:up[i-1][j]+1;
				}
			}
			lo=m;
			for(int j=m-1;j>=0;j--){
				if(A[i][j])rigt[i][j]=m,lo=j;
				else {
					rigt[i][j]=i==0?lo-1:min(rigt[i-1][j],lo-1);
					ans=max(ans,up[i][j]*(rigt[i][j]-let[i][j]+1));
				}
			}
		}
		cout<<ans*3<<endl;
	}
}


