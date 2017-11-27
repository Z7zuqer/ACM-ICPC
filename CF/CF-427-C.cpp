#include<bits/stdc++.h>
using namespace std;
int mp[110][110][12];
int getare(int x1,int y1,int x2,int y2,int k){
	int a1=mp[x1-1][y1-1][k];
	int a2=mp[x1-1][y2][k];
	int a3=mp[x2][y1-1][k];
	return mp[x2][y2][k]-a2-a3+a1;
}
int main(){
	int n,q,c;
	scanf("%d%d%d",&n,&q,&c);
	for(int i=1;i<=n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		mp[x][y][0]=(mp[x][y][0]+z)%(c+1);
		for(int i=1;i<=c;i++)
			mp[x][y][i]=(z+i)%(c+1);
	}
	for(int k=0;k<=c;k++){
		for(int i=1;i<=100;i++)
			for(int j=1;j<=100;j++)
				mp[i][j][k]+=mp[i-1][j][k];
		for(int i=1;i<=100;i++)
			for(int j=1;j<=100;j++)
				mp[i][j][k]+=mp[i][j-1][k];
	}
	while(q--){
		int t,x1,y1,x2,y2;
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		printf("%d\n",getare(x1,y1,x2,y2,t%(c+1)));
	}		
}


