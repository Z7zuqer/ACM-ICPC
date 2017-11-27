#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int maxv[50010],magic,minv[50010],n,m;
int A[50010];
int query_min(int x,int y){
	int x_p=x/magic,y_p=y/magic,r=1e9;
	if(x_p==y_p)
		for(int i=x;i<=y;i++)r=min(r,A[i]);
	else{
		r=minv[x];
		for(int i=x_p+1;i<y_p;i++)r=min(r,minv[i*magic]);
		for(int i=y_p*magic;i<=y;i++)r=min(r,A[i]);
	}
	return r;
} 
int query_max(int x,int y){
	int x_p=x/magic,y_p=y/magic,r=0;
	if(x_p==y_p)
		for(int i=x;i<=y;i++)r=max(r,A[i]);
	else{
		r=maxv[x];
		for(int i=x_p+1;i<y_p;i++)r=max(r,maxv[i*magic]);
		for(int i=y_p*magic;i<=y;i++)r=max(r,A[i]);
	}
	return r;
} 
void update_min(int x){
	int l=(x/magic)*magic,r=min(l+magic,n)-1;
	if(x==r)minv[x]=A[x],x--;
	for(;x>=l;x--)minv[x]=min(minv[x+1],A[x]);
}
void update_max(int x){
	int l=(x/magic)*magic,r=min(l+magic,n)-1;
	if(x==r)maxv[x]=A[x],x--;
	for(;x>=l;x--)maxv[x]=max(maxv[x+1],A[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	magic=sqrt(n);int size=n/magic;
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=size;i++)update_min(min(magic*i,n)-1);
	for(int i=1;i<=size;i++)update_max(min(magic*i,n)-1);
	//for(int i=1;i<=n;i++)cout<<maxv[i]<<" ";cout<<endl;
	//for(int i=1;i<=n;i++)cout<<minv[i]<<" ";cout<<endl;
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",query_max(x,y)-query_min(x,y));
	}
}
