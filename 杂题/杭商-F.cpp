#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[210][2010],B[210][2010],G[210][2010];
LL prea[2010][210],preb[2010][210],preg[2010][210];
int main(){
	int n,m,b,g;
	while(scanf("%d%d%d%d",&n,&m,&b,&g)==4){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				LL x;int y;
				scanf("%lld%d",&x,&y);
				if(x<0)A[i][j]=-1e13;
				else A[i][j]=x;
				if(y==1)B[i][j]=1,G[i][j]=0;
				else B[i][j]=0,G[i][j]=1;
			}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				prea[i][j]=prea[i][j-1]+A[j][i];
				preb[i][j]=preb[i][j-1]+B[j][i];
				preg[i][j]=preg[i][j-1]+G[j][i];
			}
		}
		LL maxv=-1;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++){
				LL nowsum=0,nowb=0,nowg=0;
				for(int k=1;k<=m;k++){
					nowsum+=(prea[k][j]-prea[k][i-1]);
					nowb+=(preb[k][j]-preb[k][i-1]);
					nowg+=(preg[k][j]-preg[k][i-1]);
					if(nowsum<0)
						nowsum=nowb=nowg=0;
					else {
						if(nowb>=b&&nowg>=g&&nowsum>maxv)
							maxv=nowsum;
					}
				}
			}
		if(maxv==-1)printf("No solution!\n");
		else printf("%lld\n",maxv);
	}
}


