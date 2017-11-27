#include<bits/stdc++.h>
using namespace std;
const int maxn=50010;
int fa[maxn],rk[maxn];
vector<int>v;
int find(int x){
	if(x==fa[x])return x;
	int t=fa[x];
	fa[x]=find(fa[x]);
	rk[x]=(rk[x]+rk[t])%3;
	return fa[x];
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(z>n||y>n){
			v.push_back(i);
			continue;
		}
		if(x==1){
			int fx=find(z),fy=find(y);
			if(fx==fy){
				if((rk[y]-rk[z]+3)%3)v.push_back(i);
				continue;
			}
			fa[fy]=fa[fx];
			rk[fy]=(rk[z]-rk[y]+3)%3;
		}
		if(x==2){
			if(z==y){
				v.push_back(i);
				continue;
			}
			int fx=find(z),fy=find(y);
			if(fx==fy){
				if((rk[y]-rk[z]+3)%3!=1)v.push_back(i);
				continue;
			}
			fa[fy]=fx;
			rk[fy]=(rk[z]-rk[y]+4)%3;
		}
	}
	for(int i=0;i<v.size();i++)printf("%d ",v[i]);
}


