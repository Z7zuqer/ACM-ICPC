#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int sta[5][5],lst[5][5];
int tmp[5][5];
int po[20];
int gethash(){
	int res=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			res+=tmp[i][j]*po[i*4+j];
	return res;
}
void back(int res){
	for(int i=3;i>=0;i--)
		for(int j=3;j>=0;j--){
			tmp[i][j]=res/po[i*4+j];
			if(tmp[i][j])res-=po[i*4+j];
		}
}
bool judge(){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(lst[i][j]!=tmp[i][j])return false;
	return true;
}
struct node{
	int res,step;
};
void print(){
	for(int i=0;i<4;i++,puts(""))
		for(int j=0;j<4;j++)
			cout<<tmp[i][j];
}
int vis[1323123];
int bfs(){
	queue<node>q;
	int h=gethash();
	q.push({h,0});vis[h]=1;
//	back(h);print();
	while(!q.empty()){
		int k=q.front().res,step=q.front().step;q.pop();
		back(k);//print();
		if(judge())return step;
		for(int x=0;x<4;x++)
			for(int y=0;y<4;y++){
				if(tmp[x][y]){
					for(int i=0;i<4;i++){
						int tx=x+dx[i];
						int ty=y+dy[i];
						if(tx>=0&&ty>=0&&tx<4&&ty<4&&!tmp[tx][ty]){
							tmp[x][y]=0;tmp[tx][ty]=1;int r=gethash();
							if(!vis[r]){
								vis[r]=1;
								q.push({r,step+1});
							}
							tmp[x][y]=1;tmp[tx][ty]=0;
						}
					}
				}
			}
	}
	return 0;
}
int main(){
	for(int i=0;i<=19;i++)po[i]=pow(2,i);//,cout<<po[i]<<endl;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			scanf("%1d",&sta[i][j]),tmp[i][j]=sta[i][j];//,cout<<sta[i][j]<" ";
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			scanf("%1d",&lst[i][j]);
	cout<<bfs()<<endl;
}
