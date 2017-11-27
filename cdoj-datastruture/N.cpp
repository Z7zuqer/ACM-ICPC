#include<bits/stdc++.h>
using namespace std;
const int maxn=1000100;
int fa[maxn],rk[maxn];
int find(int x){
	if(fa[x]==x)return x;
	int t=fa[x];
	fa[x]=find(fa[x]);
	rk[x]=rk[x]^rk[t];
	return fa[x];
}
int main(){
	//cout<<(1^1)<<endl;
	int n,m; 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&z,&x,&y);
		if(z==0){
			int fx=find(x),fy=find(y);
			if(fx==fy){
				if(rk[x]==rk[y])return 0*printf("NO\n");
				continue;
			}
			fa[fy]=fx;
			rk[fy]=rk[y]^rk[x]^1;
		}
		if(z==1){
			int fx=find(x),fy=find(y);
			if(fx==fy){
				if(rk[x]!=rk[y])return 0*printf("NO\n");
				continue;
			}
			fa[fy]=fx;
			rk[fy]=rk[y]^rk[x]^0;
		}
	}
	puts("YES");
}


