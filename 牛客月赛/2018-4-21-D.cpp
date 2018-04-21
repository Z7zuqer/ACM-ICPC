#include<bits/stdc++.h>
using namespace std;
int deg[210],fa[210];
int find(int x){
	return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(deg,0,sizeof deg);
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			deg[x]++;deg[y]++;
			int fx=find(x);
			int fy=find(y);
			if(fx!=fy)fa[fx]=fy;
		}
		int flg=1;
		for(int i=2;i<=n;i++)
			if(find(i)!=find(i-1)){
				flg=0;
				break;
			}
		if(!flg){
			puts("Xun");
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(deg[i]&1)
				cnt++;
		if(cnt<=2)puts("Zhen");
		else puts("Xun");
	}
}


