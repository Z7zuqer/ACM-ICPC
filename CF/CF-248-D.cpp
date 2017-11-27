#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int n,m,mp[maxn][maxn];
int L[maxn][maxn],R[maxn][maxn],U[maxn][maxn],D[maxn][maxn];
void update(int x,int y){
	mp[x][y]^=1;
	for(int i=1;i<=n;i++)
		if(mp[i][y])U[i][y]=U[i-1][y]+1;
		else U[i][y]=0; 
	for(int i=n;i>=1;i--)
		if(mp[i][y])D[i][y]=D[i+1][y]+1;
		else D[i][y]=0;
	for(int i=1;i<=m;i++)
		if(mp[x][i])L[x][i]=L[x][i-1]+1;
		else L[x][i]=0;
	for(int i=m;i>=1;i--)
		if(mp[x][i])R[x][i]=R[x][i+1]+1;
		else R[x][i]=0;
} 
/*
3 3 4
1 1 1
1 1 1
1 1 1
1 2 2
2 2 1
*/
int query(int x,int y){
	int maxU=U[x][y],maxD=D[x][y],ans=0; 
	if(mp[x][y])ans=max(ans,maxD+maxU-1);
	//cout<<maxD<<" "<<maxU<<endl;
	for(int j=y+1;j<=m;j++){
		maxU=min(maxU,U[x][j]);
		maxD=min(maxD,D[x][j]);
		ans=max(ans,(j-y+1)*(maxD+maxU-1));
	}
	maxU=U[x][y],maxD=D[x][y];
	for(int j=y-1;j>=1;j--){
		maxU=min(maxU,U[x][j]);
		maxD=min(maxD,D[x][j]);
		ans=max(ans,(y-j+1)*(maxD+maxU-1));
	}
	int maxL=L[x][y],maxR=R[x][y];
	if(mp[x][y])ans=max(ans,maxL+maxR-1);
	for(int i=x-1;i>=1;i--){
		maxL=min(maxL,L[i][y]);
		maxR=min(maxR,R[i][y]);
		ans=max(ans,(x-i+1)*(maxL+maxR-1));
	}
	maxL=L[x][y];maxR=R[x][y];
	for(int i=x+1;i<=n;i++){
		maxL=min(maxL,L[i][y]);
		maxR=min(maxR,R[i][y]);
		ans=max(ans,(i-x+1)*(maxL+maxR-1)); 
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	int q;
	scanf("%d",&q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mp[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j])L[i][j]=L[i][j-1]+1;
			else L[i][j]=0;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			if(mp[i][j])R[i][j]=R[i][j+1]+1;
			else R[i][j]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j])U[i][j]=U[i-1][j]+1;
			else U[i][j]=0;
	for(int i=n;i>=1;i--)
		for(int j=1;j<=m;j++)
			if(mp[i][j])D[i][j]=D[i+1][j]+1;
			else D[i][j]=0;
	for(int i=1;i<=q;i++){
		int k,x,y;
		scanf("%d%d%d",&k,&x,&y);
		if(k==1)update(x,y);
		if(k==2)printf("%d\n",query(x,y));
	}
}


