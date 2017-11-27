#include<bits/stdc++.h>
using namespace std;
const int maxn=200200;
int block[maxn],A[maxn],magic,size[maxn];
void update(int x,int y){
	int x_pos=x/magic;
	(*lower_bound(block+x_pos*magic,block+x_pos*magic+size[x_pos],A[x]))=y;
	sort(block+x_pos*magic,block+x_pos*magic+size[x_pos]);
	A[x]=y;
}
int query_min(int x,int y,int k){
	int x_pos=x/magic,y_pos=y/magic,r=0;
	if(x_pos==y_pos)
		for(int i=x;i<=y;i++)r+=A[i]<k;
	else {
		for(int i=x;i<=x_pos*magic+size[x_pos]-1;i++)r+=A[i]<k;
		for(int i=y_pos*magic;i<=y;i++)r+=A[i]<k;
		for(int i=x_pos+1;i<y_pos;i++)r+=lower_bound(block+i*magic,block+i*magic+size[i],k)-block-i*magic;
	}
	return r;
}
int query_max(int x,int y,int k){
	int x_pos=x/magic,y_pos=y/magic,r=0;
	if(x_pos==y_pos)
		for(int i=x;i<=y;i++)r+=A[i]>k;
	else {
		for(int i=x;i<=x_pos*magic+size[x_pos]-1;i++)r+=A[i]>k;
		for(int i=y_pos*magic;i<=y;i++)r+=A[i]>k;
		for(int i=x_pos+1;i<y_pos;i++)r+=size[i]-(upper_bound(block+i*magic,block+i*magic+size[i],k)-block-i*magic);
	}
	return r;
}
int main(){
	int n,m;
	long long ans=0;
	scanf("%d%d",&n,&m);
	magic=sqrt(n);int sz=n/magic;
	for(int i=1;i<=n;i++)A[i]=block[i]=i;
	for(int i=0;i<=sz;i++)size[i]=min(magic,n-i*magic);
	for(int i=0;i<=sz;i++)sort(block+i*magic,block+i*magic+size[i]);
	while(m--){
		int x,y,r=0;
		scanf("%d%d",&x,&y);
		if(x>y)swap(x,y);
		int v_x=A[x],v_y=A[y];
		if(x==y){
			printf("%lld\n",ans);
			continue;
		}
		ans+=query_max(x,y,v_x);
		ans-=query_min(x,y,v_x);
		ans-=query_max(x+1,y,v_y);
		ans+=query_min(x+1,y,v_y);
		update(x,v_y);
		update(y,v_x);
		printf("%lld\n",ans);
	}
}


