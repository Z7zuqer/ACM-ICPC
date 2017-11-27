#include<bits/stdc++.h>
using namespace std;
int fa[100100<<1];
int n,m;
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void uni(int x,int y){
	int a=find(x);
	int b=find(y);
	int c=find(x+n);
	int d=find(y+n);
	if(a!=d)fa[a]=d;
	if(c!=d)fa[c]=b;
}
int main(){
	int T;
	freopen("meciul.in","r",stdin);
	freopen("meciul.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n+n;i++)fa[i]=i;
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			int x=find(a);
			int y=find(b);
			if(x==y)
				cout<<"NO"<<endl;
			else {
				uni(a,b);
				cout<<"YES"<<endl;
			}
		}
	}
}


