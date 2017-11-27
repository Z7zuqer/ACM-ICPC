#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn = 4000+7;
int n,m,ans[maxn],path[maxn][maxn];
struct node{
	int x,idx;
}A[maxn],B[maxn];
LL dp[2][maxn];
int cmp(node m,node n){
	return m.x<n.x;
}
void dfs(int x, int y) {
	if(!x||!y)return ;
	ans[A[x].idx]=B[y].idx;
	dfs(x-1,y-path[x][y]);
}
int getdis(int x,int y){
	return abs(x-y);
}
int main(){
	freopen("evacuation.in","r",stdin);
	freopen("evacuation.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i].x);
		A[i].idx=i;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&B[i].x);
		B[i].idx=i;
	}
	sort(A+1,A+1+n,cmp);
	sort(B+1,B+1+m,cmp);
	for(int i=1;i<=m;i++)dp[0][i]=1e17;
	dp[0][0]=0;
	int now,pre;
	for(int i=1;i<=n;i++){
		now=i&1;
		pre=now^1;
		for(int j=0;j<=m;j++)dp[now][j]=1e17;
		for(int j=1;j<=m&&j<=i;j++){
			if(dp[pre][j-1]<dp[pre][j]){
				dp[now][j]=dp[pre][j-1]+getdis(A[i].x,B[j].x);
				path[i][j]=1;
			} 
			else{
				dp[now][j]=dp[pre][j]+getdis(A[i].x,B[j].x);
				path[i][j]=0;
			}
		}
	}
	printf("%lld\n",dp[n&1][m]);
	dfs(n,m);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}
