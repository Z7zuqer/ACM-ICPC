#include<bits/stdc++.h>
using namespace std;
#define LL long long 
LL mp[2010][2010];
LL sum1[2010][2010],sum2[2010][2010];
int n;
int check(int x,int y,int xx,int yy){
	int remy=abs(yy-y);
	int remx=abs(xx-x);
	if(remy==remx)return 0;
	return 1;
}
LL getsum(int i,int j){
	LL s1=0,s2=0;
	int x1=j-1+i,y1=1;
	if(x1<=n)s1=sum2[x1][y1];
	int x2=n,y2=j-n+i;
	if(y2>=1)s1=sum2[x2][y2];
	
	x1=n-j+i,y1=n;
	if(x1<=n)s2=sum1[x1][y1];
	x2=n,y2=j+n-i;
	if(y2<=n)s2=sum1[x2][y2];
	
	return s1+s2-mp[i][j];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%I64d",&mp[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			sum1[i][j]=sum1[i-1][j-1]+mp[i][j];
	for(int i=1;i<=n;i++)
		for(int j=n;j>=1;j--)	
			sum2[i][j]=sum2[i-1][j+1]+mp[i][j];
	LL maxv1=sum2[1][1]+sum1[n][n]-1;
	LL maxv2=sum2[2][1]+sum1[n-1][n]-1;
	int x=1,y=1,xx=1,yy=2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			LL sum=getsum(i,j);
			if((i+j)%2==1&&sum>maxv2){
				x=i;
				y=j;
				maxv2=sum;
			}
			if((i+j)%2==0&&sum>maxv1){
				maxv1=sum;
				xx=i;
				yy=j;
			}
		}
	}
	printf("%I64d\n%d %d %d %d\n",maxv1+maxv2,x,y,xx,yy);
}
