#include<bits/stdc++.h>
using namespace std;
int n,dis[400000],cnt=0,vis[400000];
map<string,int>mp;
map<int,string>mpp;
int num[11];
int getid(string a){
	if(!mp[a])mp[a]=++cnt,mpp[cnt]=a;
	return mp[a];
}
int bfs(string sta,string end){
	int stanum=getid(sta);
	int endnum=getid(end);
	if(stanum==endnum)return 0;
	memset(dis,128,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[stanum]=0;vis[stanum]=1;
	queue<int>q;
	q.push(stanum);
	while(!q.empty()){
		int k=q.front();q.pop();string sk=mpp[k];
		if(k==endnum)return dis[k];
		for(int i=0;i<n;i++)num[i+1]=sk[i]-'0';
		//for(int i=1;i<=n;i++)cout<<num[i];cout<<endl;
		for(int i=2;i<=n;i++){
			string tx="";tx+=(char)('0'+num[i]);
			for(int j=2;j<i;j++)tx+=(char)('0'+num[j]);
			tx+=(char)('0'+num[1]);
			for(int j=i+1;j<=n;j++)tx+=(char)('0'+num[j]);
			//cout<<tx<<endl;
			int txid=getid(tx);
			if(txid==endnum)return dis[k]+1;
			if(!vis[txid]){
				vis[txid]=1;
				dis[txid]=dis[k]+1;
				q.push(txid);
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int times=1;times<=5;times++){
		string a,b;
		cin>>a>>b;
		printf("%d\n",bfs(a,b));
	} 
}


