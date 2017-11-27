#include<bits/stdc++.h>
using namespace std;
int k,flg;
int ans[5][5]={{1,1,1,1,1},{0,1,1,1,1},{0,0,2,1,1},{0,0,0,0,1},{0,0,0,0,0}},sta[5][5];
int dx[8]={1,1,-1,-1,2,2,-2,-2};
int dy[8]={2,-2,2,-2,1,-1,1,-1};
int judge(int a[5][5],int x,int y){
	if(x!=2||y!=2)return 0;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++){
			if(a[i][j]!=ans[i][j])return 0;
		}
	return 1;
} 
int eva(int a[5][5],int s){
	int v=0;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			if(a[i][j]!=ans[i][j]){
				v++;
				if(v+s>k)
					return 0;
			}
	return 1;
}
void dfs(int a[5][5],int x,int y,int step){
	if(step>=k){
		if(judge(a,x,y))flg=1;
		return ;
	}
	if(flg)return ;
	for(int i=0;i<8;i++){
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(tx>=0&&ty>=0&&tx<5&&ty<5){
			swap(a[x][y],a[tx][ty]);
			if(eva(a,step))dfs(a,tx,ty,step+1);
			swap(a[x][y],a[tx][ty]);
		}
	}
}
int main(){
	int t;
	//cout<<(int)"*"<<endl;
	scanf("%d",&t);
	while(t--){
		flg=0;
		int sx,sy;
		char s[10];
		for(int i=0;i<5;i++){
			scanf("%s",s);
			for(int j=0;j<5;j++){
				if(s[j]=='*')sta[i][j]=2,sx=i,sy=j;
				else sta[i][j]=s[j]-'0';
			}
		}
		for(k=1;k<=15;k++){
			dfs(sta,sx,sy,0);
			if(flg){
				printf("%d\n",k);
				break;
			}
		}
		if(!flg)printf("-1\n");
	}
}
