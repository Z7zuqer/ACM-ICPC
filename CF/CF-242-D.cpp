#include<bits/stdc++.h>
using namespace std;
int mp[310][310];
int sum[310][310][4];
int n,m,tu,tp,td;
int work(int a,int b){
	if(a==b)return tp;
	if(a>b)return td;
	return tu;
}
int main(){
	int n,m;
	int t;
	scanf("%d%d%d%d%d%d",&n,&m,&t,&tp,&tu,&td);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mp[i][j]);
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
			sum[i][j][0]=sum[i-1][j][0]+work(mp[i-1][j],mp[i][j]);
	for(int i=n-1;i>=1;i--)
		for(int j=1;j<=m;j++)
			sum[i][j][1]=sum[i+1][j][1]+work(mp[i+1][j],mp[i][j]);
	for(int j=2;j<=m;j++)
		for(int i=1;i<=n;i++)
			sum[i][j][2]=sum[i][j-1][2]+work(mp[i][j-1],mp[i][j]);
	for(int j=m-1;j>=1;j--)
		for(int i=1;i<=n;i++)
			sum[i][j][3]=sum[i][j+1][3]+work(mp[i][j+1],mp[i][j]);
	int absmin=1e9;
	int staL=-1,staR=-1,endL=-1,endR=-1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int endi=i+2;endi<=n;endi++)
				for(int endj=j+2;endj<=m;endj++){
					int nowsum=sum[i][endj][2]-sum[i][j][2];
					nowsum+=sum[i][j][1]-sum[endi][j][1];
					nowsum+=sum[endi][endj][0]-sum[i][endj][0];
					nowsum+=sum[endi][j][3]-sum[endi][endj][3];
					//cout<<nowsum<<endl;
					if(nowsum==t)return 0*printf("%d %d %d %d\n",i,j,endi,endj);
					if(abs(nowsum-t)<absmin){
						absmin=abs(nowsum-t);
						staL=i;staR=j;
						endL=endi;endR=endj;
					}
				}
	printf("%d %d %d %d\n",staL,staR,endL,endR);
	//cout<<staL<<" "<<staR<<" "<<endL<<" "<<endR<<endl;
}


