#include<bits/stdc++.h>
using namespace std;
int n,col[15];
map<int,int>mp;
int check(){
	for(int i=1;i<=n-3;i++){
		int flg=1,vis[5]={0,0,0,0,0};
		for(int j=0;j<4;j++){
			if(vis[col[i+j]])flg=0;
			vis[col[i+j]]=1;
		}
		if(flg)return 1;
	}
	return 0;
}
int hash(){
	int r=0;
	for(int i=1;i<=n;i++)r=r*10+col[i]; 
	return r;
}
int ans=0;
void dfs(int now){
	if(now>n){
		int flg=check(),hashnum=hash();
		if(flg){
			if(!mp[hashnum]){
				cout<<hashnum<<endl;
				mp[hashnum]=1;
				ans++;
			}
		}
		return ;
	}
	col[now]=1;
	dfs(now+1);
	col[now]=2;
	dfs(now+1);
	col[now]=3;
	dfs(now+1);
	col[now]=4;
	dfs(now+1);
}
int main(){
	n=5;
	dfs(1);
	cout<<ans<<endl;
}


