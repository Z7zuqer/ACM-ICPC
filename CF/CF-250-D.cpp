#include<bits/stdc++.h>
using namespace std;
int fa[100100];
long long rk[100100],A[100100];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
struct node{
	int s,e;
}r[100100];
int cmp(const node& m,const node& n){
	return min(A[m.s],A[m.e])>min(A[n.s],A[n.e]);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i,rk[i]=1;
	for(int i=1;i<=n;i++)scanf("%I64d",&A[i]);
	for(int i=1;i<=m;i++)scanf("%I64d%I64d",&r[i].s,&r[i].e);
	sort(r+1,r+1+m,cmp);
	double ans=0;
	for(int i=1;i<=m;i++){
		int x=r[i].s,y=r[i].e;
		int fx=find(x),fy=find(y);
		//cout<<a<<" "<<b<<" ";
		if(fx==fy)continue;
		//cout<<siz1<<" "<<siz2<<endl;
		long long v=min(A[x],A[y]);
		ans+=rk[fx]*rk[fy]*v;
		fa[fy]=fx;
		rk[fx]+=rk[fy];
	}
	ans=2.0*ans/((n*1LL-1)*n*1.0);
	printf("%.6lf\n",ans);
} 
