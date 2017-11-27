#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	if((n/2)==0&&k>0)return 0*printf("-1\n");
	if(k<floor(n/2))return 0*printf("-1\n");
	if(n==1)return 0*printf("1\n");
	int all=n/2;
	int r=k-all+1;
	if(r==1)printf("1 %d ",(r=2));
	else printf("%d %d ",r,r*2),r=r*2;
	int sta=r;
	for(int i=1;i<=(all-1)*2;i+=2)printf("%d %d ",sta+i,sta+i+1);
	if(n&1)printf("%d\n",sta+(all-1)*2+1);
}


