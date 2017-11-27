#include<bits/stdc++.h>
using namespace std;
int A[110][110],B[110][110];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&A[i][j]);
	int r,c;
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			scanf("%d",&B[i][j]);
	int maxv=1e9,sta=-1,end=-1;
	for(int i=1;i+r-1<=n;i++)
		for(int j=1;j+c-1<=m;j++){
			int sum=0;
			for(int ii=0;ii<r;ii++)	
				for(int jj=0;jj<c;jj++)
					sum+=abs(B[1+ii][1+jj]-A[i+ii][j+jj]);
			if(sum<maxv){
				maxv=sum;
				sta=i;end=j;
			}
		}
	for(int i=0;i<r;i++,puts(""))
		for(int j=0;j<c;j++)
			printf("%d ",A[sta+i][end+j]);
}


