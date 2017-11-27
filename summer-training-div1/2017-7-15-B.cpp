#include<bits/stdc++.h>
using namespace std;
int mp[45][45];
int main(){
	int n;
	scanf("%d",&n);
	if(n==1)return 0*printf("1\n1\n");
	if(n==3||n==2)return 0*printf("-1\n");
	int nowx=n,nowy=1,num=1;
	for(int i=1;i<=n;i++){
		int mid=n/2+1,sta=num;
		for(int j=1;j<mid;j++)mp[nowx][j]=sta+j*2-1;
		mp[nowx][mid]=sta;
		for(int j=mid+1;j<=n;j++)mp[nowx][j]=sta+(j-mid)*2;
		nowx=(nowx-2)>=1?nowx-2:n-1;num+=n;
	}
	printf("%d\n",n);
	for(int i=1;i<=n;i++,cout<<endl)
		for(int j=1;j<=n;j++)
			printf("%d ",mp[i][j]);
}
