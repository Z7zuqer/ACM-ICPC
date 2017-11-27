#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
long long dis[maxn];
int n,m,k,vis[maxn];
struct NODE{
	int e;
	long long va; 
};
vector<NODE>v[maxn];
struct {
	int s,e;
	long long va;
}ed[maxn*4];
struct node{
	long long first;
	int second;
	friend bool operator<(node m,node n){
		return m.first<n.first;
	}
}; 
int vvis[maxn];
void dij(){
	priority_queue<node>q;
	for(int i=1;i<=n;i++)dis[i]=1e17+7;
	dis[1]=0;
	q.push({0,1});
	while(!q.empty()){
		int k=q.top().second;
		long long va=q.top().first;q.pop();
		if(va>dis[k])continue;
		if(vvis[k])continue;
		vvis[k]=1;
		for(int i=0;i<v[k].size();i++){
			int e=v[k][i].e;
			long long va=v[k][i].va;
			if(dis[k]+va<dis[e]&&!vvis[e]){
				vvis[e]=1;
				dis[e]=dis[k]+va;
				q.push({va,e});
			}
		}
	}
}
long long req[maxn];
struct {
	long long e,va;
}tra[100100];
int in[maxn];
void work(){
	for(int i=1;i<=m;i++){
		int e=ed[i].s,k=ed[i].e;
		long long va=ed[i].va;
		if(dis[e]==dis[k]+va)in[e]++;
		if(dis[k]==dis[e]+va)in[k]++;
	}
}
inline bool scan_d(int &num)  
{
        char in;bool IsN=false;
        in=getchar();
        if(in==EOF) return false;
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();
        if(in=='-'){ IsN=true;num=0;}
        else num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
        if(IsN) num=-num;
        return true;
}
int main(){
	//for(int i=1;i<=n;i++)req[i]=1e9+1;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scan_d(a);scan_d(b);scan_d(c);
		if(a>b)swap(a,b); 
		v[a].push_back({b,c});
		v[b].push_back({a,c});
		ed[i]={a,b,c}; 
		if(a==1){
			if(req[b]==0)req[b]=c;
			else req[b]=min(req[b],c*1LL);
		}
	}
	int ans=0,all=0;
	for(int i=1;i<=k;i++){
		int a,b;
		scan_d(a);scan_d(b);
		if(req[a]&&req[a]<=b){
			ans++;
			//cout<<a<<endl;
			continue;
		}
		v[1].push_back({a,b});
		v[a].push_back({1,b});
		tra[++all]={a,b};
		req[a]=b;
	}
	dij();
	work();
	//cout<<"dSA"<<endl;
	//for(int i=1;i<=n;i++)cout<<dis[i]<<" ";cout<<endl;
	for(int i=1;i<=all;i++){
		//if(tra[i].e==0)continue;
		long long e=tra[i].e,va=tra[i].va;
		if(va>dis[e])ans++;
		if(va==dis[e]&&in[e]>=1)ans++;
	}
	printf("%d\n",ans);
}
