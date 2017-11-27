#include<bits/stdc++.h>
using namespace std;
#define LL long long
map<string,int>mp;
map<int,string>mpp;
vector<int>v[10];
int vis[10];
LL L[10][10],R[10][10],ansk,rel,rer,m;
string ansr;
double res=0;
void dfs(int u){
	vis[u]=1;
	//cout<<u<<endl;
	for(int i=0;i<v[u].size();i++){
		int e=v[u][i];
		if(vis[e])continue;
		rel*=L[u][e];rer*=R[u][e];
		LL val=m*rer/rel;
		if((m*rer)%rel)val++;
		double tmp=1.0*val*rel/rer-m*1.0;
		if(val<=100000&&tmp<res){
			//cout<<mpp[u]<<" "<<mpp[e]<<endl;
			res=tmp;
			ansk=val;
			ansr=mpp[e];
		}
		dfs(e);
		rel/=L[u][e];rer/=R[u][e];
	}
	vis[u]=0;
}
int main(){
	ios_base::sync_with_stdio(false);
	int n,cas=1;
	while(cin>>n&&n){
		string a,b;
		int va,vb,cnt=0;
		mp.clear();mpp.clear();
		for(int i=0;i<10;i++)v[i].clear();
		for(int i=1;i<=n;i++){
			cin>>va>>a>>b>>vb>>b;
			if(!mp[a]){
				mp[a]=++cnt;
				mpp[cnt]=a;
			}
			if(!mp[b]){
				mp[b]=++cnt;
				mpp[cnt]=b;
			}
			int s=mp[a],e=mp[b];
			v[s].push_back(e);
			v[e].push_back(s);
			L[s][e]=va;R[s][e]=vb;
			L[e][s]=vb;R[e][s]=va;
		}
		res=1e19;
		rel=1;rer=1;
		string sss;
		ansk=0;
		cin>>m>>sss;
		memset(vis,0,sizeof vis);
		dfs(mp[sss]);
		cout<<"Case "<<(cas++)<<": "<<ansk<<" "<<ansr<<endl;
	}
}
