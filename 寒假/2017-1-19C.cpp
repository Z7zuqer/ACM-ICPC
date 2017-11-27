#include<bits/stdc++.h>
using namespace std;
const int maxn=717;
double A[maxn][maxn];
int main(){
	freopen("bujor.in","r",stdin);
	freopen("bujor.out","w",stdout);
	int T,n;
	scanf("%d",&T);
	while(T--){
		memset(A,0,sizeof(A));
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)	
				cin>>A[i][j];
		for(int i=0;i<n;i++)A[i][n+i]=1;
		for(int i=0,j=0;j<n&&i<n;j++){
			int r=i;
			for(int k=i;k<n;k++)
				if(fabs(A[k][j])>fabs(A[r][j]))r=k;
			if(fabs(A[r][j])>1e-9){
				for(int u=j;u<(n<<1);u++)
					swap(A[r][u],A[i][u]);
				for(int u=0;u<n;u++){
					if(u!=i){
						double k=A[u][j]/A[i][j];
						for(int t=j;t<(n<<1);t++)
							A[u][t]-=(A[i][t]*k);
					}
				}
				i++;
			}
		}
		for(int i=0;i<n;i++)
			for(int j=n;j<n+n;j++)
				A[i][j]/=A[i][i];
		for(int i=0;i<n;i++)
			for(int j=n;j<(n<<1);j++)
				if(j==n*2-1)printf("%.9lf\n",A[i][j]);
				else printf("%.9lf ",A[i][j]);
	}
}


