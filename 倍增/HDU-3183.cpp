#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int n,A[maxn],dp[maxn][15];
void init_ST(){
	for(int i=1;i<=n;i++)dp[i][0]=A[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int query(int s,int e){
	int r=(int)(log2(1.0*(e-s+1)));
	return min(dp[s][r],dp[1+e-(1<<r)][r]);
}
char s[maxn];
int main(){
	int m;
	while(scanf("%s%d",s,&m)==2){
		n=0;
		for(int i=0;s[i];i++)A[++n]=s[i]-'0';
		init_ST();
		vector<int>ans;
		int sta=1,end=n-(n-m)+1,cnt=n-m,k;
		while(ans.size()<n-m){
			ans.push_back(k=query(sta,end));
			for(int i=sta;i<=end;i++){
				if(A[i]==k){
					sta=i+1;
					break;
				}
			}
			--cnt;end=n-cnt+1;
		}
		int i;
		for(i=0;i<ans.size();i++)if(ans[i])break;if(i==ans.size())printf("0");
		for(;i<ans.size();i++)printf("%d",ans[i]);printf("\n");
	}
}
