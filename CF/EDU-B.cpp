#include<bits/stdc++.h>
using namespace std;
char mp[210][210];
int vis[4];
int getcol(int x,int y){
	if(mp[x][y]=='R')return 1;
	if(mp[x][y]=='B')return 2;
	return 3;
}
int check(){
	return vis[1]&&vis[2]&&vis[3];
}
int check_col(int x1,int y1,int x2,int y2){
	int col=getcol(x1,y1);vis[col]=1;
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
			if(getcol(i,j)!=col)
				return 0;
	return 1;
}
int main(){
	int n,m,flg=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	if((n%3)>0&&(m%3)>0)return 0*printf("NO\n");
	if(n%3==0){
		int div=n/3,now=1;
		for(int i=1;i<=n;i+=div){
			int col=getcol(i,1);//cout<<col<<endl;
			vis[col]=1;
			for(int j=i;j<=div&&flg;j++){
				for(int k=1;k<=m&&flg;k++)
					if(getcol(j,k)!=col){
						flg=0;
						break;
					}
			}
		}
		if(flg&&check())return 0*printf("YES\n");
	}
	flg=1;memset(vis,0,sizeof vis);
	if(m%3==0){
		int div=m/3,now=1;
		for(int i=1;i<=m;i+=div){
			int col=getcol(1,i);
			vis[col]=1;
			for(int j=1;j<=n&&flg;j++){
				for(int k=i;k<=div&&flg;k++)
					if(getcol(j,k)!=col){
						flg=0;
						break;
					}
			}
		}
		if(flg&&check())return 0*printf("YES\n");
	}
	flg=1;memset(vis,0,sizeof vis);
	if((n%2==0)&&m==n+n/2){
		int wid=n/2;
		int hei=m-wid;
		int col=getcol(1,1);vis[col]=1;
		for(int i=1;i<=n&&flg;i++)
			for(int j=1;j<=n/2&&flg;j++)
				if(getcol(i,j)!=col){
					flg=0;
					break;
				}
		col=getcol(n/2+1,n/2+1);vis[col]=1;
		for(int i=n/2+1;i<=n&&flg;i++){
			for(int j=n/2+1;j<=m&&flg;j++){
				if(getcol(i,j)!=col){
					flg=0;
					break;
				}
			}
		}
		col=getcol(1,n/2+1);vis[col]=1;
		for(int i=1;i<=n/2&&flg;i++)
			for(int j=n/2+1;j<=m&&flg;j++){
				if(getcol(i,j)!=col){
					flg=0;
					break;
				}
			}
		if(flg&&check())return 0*printf("YES\n");
		flg=1;memset(vis,0,sizeof vis);
		if(check_col(1,1,n/2,n/2)&&check_col(n/2+1,1,n,n)&&check_col(1,n+1,n,m)&&check())return 0*printf("YES\n");
	}
	flg=1;memset(vis,0,sizeof vis);
	if(((m%2)==0)&&n==m/2+m){
		int col=getcol(1,1);vis[col]=1;
		for(int i=1;i<=m/2&&flg;i++)
			for(int j=1;j<=m&&flg;j++)
				if(getcol(i,j)!=col){
					flg=0;
					break;
				}
		col=getcol(m/2+1,1);vis[col]=1;
		for(int i=m/2+1;i<=n&&flg;i++){
			for(int j=1;j<=m/2&&flg;j++){
				if(getcol(i,j)!=col){
					flg=0;
					break;
				}
			}
		}
		col=getcol(m/2+1,m/2+1);vis[col]=1;
		for(int i=m/2+1;i<=n&&flg;i++)
			for(int j=m/2+1;j<=m&&flg;j++){
				if(getcol(i,j)!=col){
					flg=0;
					break;
				}
			}
		if(flg&&check())return 0*printf("YES\n");
		flg=1;memset(vis,0,sizeof vis);
		if(check_col(1,1,m/2,m)&&check_col(1,m/2+1,m,m)&&check_col(m+1,1,n,m)&&check())return 0*printf("YES\n");
	}
	puts("NO");
}


