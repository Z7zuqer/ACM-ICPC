#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int fa[maxn];
struct node{
	int s,e,v;
}res[maxn*10];
bool cmp(node m,node n){
	return m.v<n.v;
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void uni(int a,int b){
	fa[find(b)]=find(a);
}
int n,m;
void init(){
	for(int i=0;i<=n;i++)fa[i]=i;
}
bool cek(int a,int b){
	if(find(a)==find(b))return true;
	return false;
}
int maxm=-1,minm=30001;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	//int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&res[i].s,&res[i].e,&res[i].v);
	}
	int s,t;
	sort(res,res+m,cmp);
	scanf("%d%d",&s,&t);
	double ans=1e9;
	for(int i=0;i<m;i++){
		init();
		int mx=res[i].v,mi=0x3f3f3f3f;
		for(int j=i;j>=0;j--)
			if(!cek(res[j].s,res[j].e)){
				uni(res[j].s,res[j].e);
				mi=res[j].v;
				if(cek(s,t))break;
			}
		//for(int k=1;k<=n;k++,cout<<" ")cout<<fa[k];cout<<endl;
		if(!cek(s,t))continue;//cout<<"dsa"<<endl;
		if(ans>(double)mx/(double)mi){
			maxm=mx;
			minm=mi;
			ans=(double)mx/(double)mi;
		}
	}
	if(maxm==-1&&minm==30001)cout<<"IMPOSSIBLE"<<endl;
	else {
		int ave=gcd(maxm,minm);
		if(maxm%minm==0)cout<<maxm/minm<<endl;
		else cout<<maxm/ave<<"/"<<minm/ave<<endl;
	}
}
