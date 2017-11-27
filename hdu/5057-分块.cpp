#include<bits/stdc++.h>
using namespace std;
const int maxn=100001;
unsigned short block[maxn][11][11];
int magic,size[2001],A[maxn];
void init(int k){
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
			block[k*magic+size[k]-1][i][j]=0;
	int len_=1,u_=A[k*magic+size[k]-1];
	for(int j=1;j<=9;j++){
		block[k*magic+size[k]-1][j][u_%10]++;
		u_/=10;
	}
	for(int i=k*magic+size[k]-2;i>=k*magic;i--){
		int len=1,u=A[i];
		for(int x=0;x<=10;x++)
			for(int y=0;y<=10;y++)
				block[i][x][y]=block[i+1][x][y];
		for(int j=1;j<=9;j++){
			block[i][j][u%10]++;
			u/=10;
		}
	}
}
void update(int x,int y){
	int x_pos=x/magic,v=A[x];
	for(int i=x_pos*magic;i<=x;i++){
		int tv=A[x],ty=y,tlen1=1,tlen2=1;
		for(int j=1;j<=9;j++){
			block[i][j][tv%10]--;
			tv/=10;
		}
		for(int j=1;j<=9;j++){
			block[i][j][ty%10]++;
			ty/=10;
		}
	}
}
int query(int x,int y,int d,int p){
	int x_pos=x/magic,y_pos=y/magic,r=0;
	if(x_pos==y_pos)return block[x][d][p]-(((y+1)%magic==0)?0:block[y+1][d][p]);
	else {
		r+=block[x][d][p];
		for(int i=x_pos+1;i<y_pos;i++)r+=block[i*magic][d][p];
		r+=block[y_pos*magic][d][p]-(((y+1)%magic==0)?0:block[y+1][d][p]);
	}
	return r;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		//memset(block,0,sizeof(block));
		for(int i=0;i<n;i++)scanf("%d",&A[i]);
		magic=sqrt(n)+5;int sz=n/magic;
		for(int i=0;i<=sz;i++)size[i]=min(magic,n-i*magic);
		for(int i=0;i<=sz;i++)init(i);
		char s[2];
		while(m--){
			scanf("%s",s);
			if(s[0]=='Q'){
				int x,y,d,p;
				scanf("%d%d%d%d",&x,&y,&d,&p);
				printf("%d\n",query(x-1,y-1,d,p));
			}
			if(s[0]=='S'){
				int x,y;
				scanf("%d%d",&x,&y);
				update(x-1,y);
			}
		}
	}
}

