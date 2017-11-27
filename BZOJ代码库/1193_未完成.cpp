#include<bits/stdc++.h>
using namespace std;
int xp,yp,xs,ys;
int dx[8]={1,2,1,2,-1,-2,-1,-2};
int dy[8]={2,1,-2,-1,2,1,-2,-1};
struct node{
	int x,y;
};
map<node,int>mp;
void bfs(){
	queue<node>q;
	q.push({xp,yp});
	mp[{xp,yp}]=1;
	while(!q.empty()){
		int x=q.front().x,y=q.front().y;q.pop();
		for(int i=0;i<8;i++){
			int tx=x+dx[i];
			int ty=y+dy[i];
			if(tx>=1!mp[{tx,ty}])
		}
	}
}
int main(){
	
}
