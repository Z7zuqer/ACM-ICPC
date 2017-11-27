#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int A[100100],a,b,n,fa[100100];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void uni(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(rand()&1)fa[fx]=fy;
	else fa[fy]=fx;
}
int main(){
	srand(time(0));
	scanf("%d%d%d",&n,&a,&b);
	int cnt=0,S=n+1,T=n+2;
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		mp[A[i]]=++cnt;
	}
	for(int i=1;i<=n+2;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		if(mp[a-A[i]])uni(mp[A[i]],mp[a-A[i]]);
		else uni(T,mp[A[i]]);
		if(mp[b-A[i]])uni(mp[A[i]],mp[b-A[i]]);
		else uni(S,mp[A[i]]);
	}
	if(find(S)==find(T))return 0*printf("NO\n");
	puts("YES");
	for(int i=1;i<=n;i++)
		if(find(mp[A[i]])==find(S))printf("0 ");
		else printf("1 ");
	cout<<endl;
}


