#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
struct SAT{
	int n;
	vector<int>v[maxn*2];
	int mark[maxn*2],sta[maxn*2],top;
	int dfs(int u){
		if(mark[u^1])return 0;
		if(mark[u])return 1;
		mark[u]=1;
		sta[top++]=u;
		for(int i=0;i<v[u].size();i++)if(!dfs(v[u][i]))return 0;
		return 1;
	}
	void init(int n){
		this->n=n;
		for(int i=0;i<n*2;i++)mark[i]=0,v[i].clear();
	}
	void add(int s,int sv,int e,int ev){
		int x=s*2+sv;
		int y=e*2+ev;
		v[x].push_back(y^1);
		v[y].push_back(x^1);
	}
	int work(){
		for(int i=0;i<n*2;i+=2){
			if(!mark[i]&&!mark[i^1]){
				top=0;
				if(!dfs(i)){
					while(top>0)mark[sta[--top]]=0;
					if(!dfs(i^1))return 0;
				}
			}
		}
		return 1;
	}
}sat;
int n,mp[maxn][2];
int check(int k){
	sat.init(n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int a=0;a<2;a++){
				for(int b=0;b<2;b++){
					if(abs(mp[i][a]-mp[j][b])<k)
						sat.add(i-1,a,j-1,b);
				}
			}
		}
	}
	return sat.work();
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d%d",&mp[i][0],&mp[i][1]);
		}	
		int l=0,r=1e7+7,res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid))l=mid+1,res=mid;
			else r=mid-1;
		}
		printf("%d\n",res);
	}
}


