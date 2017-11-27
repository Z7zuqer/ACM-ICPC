#include<bits/stdc++.h>
using namespace std;
const int maxn=310;
int fa[maxn];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
bool uni(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a!=b){
		fa[b]=a;
		return true;
	}
	return false;
}
struct node{
	int s,e,v;
}a[maxn*maxn*2];
bool cmp(node m,node n){
	return m.v<n.v;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].v);
	}
	for(int i=0;i<=n;i++)fa[i]=i;
	sort(a,a+m,cmp);
	int maxm=0,e=0;
	for(int i=0;i<m;i++){
		if(uni(a[i].s,a[i].e)){
			e++;
			maxm=max(maxm,a[i].v);
		}
		if(e==n-1)break;
	}
	printf("%d %d\n",n-1,maxm);
} 
