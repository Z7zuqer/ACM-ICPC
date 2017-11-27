#include<bits/stdc++.h>
using namespace std;
const int maxn=50010;
int magic,block[maxn],size[maxn],A[maxn],n,m;
void update(int x,int y){
	int x_pos=x/magic;
	(*lower_bound(block+x_pos*magic,block+x_pos*magic+size[x_pos],A[x]))=y;
	sort(block+x_pos*magic,block+x_pos*magic+size[x_pos]);
	A[x]=y;
}
int count_(int x,int y,int k){
	int x_pos=x/magic,y_pos=y/magic,r=0;
	if(x_pos==y_pos)
		for(int i=x;i<=y;i++)r+=k>A[i];
	else {
		for(int i=x;i<=x_pos*magic+size[x_pos]-1;i++)r+=k>A[i];
		for(int i=y_pos*magic;i<=y;i++)r+=k>A[i];
		for(int i=x_pos+1;i<y_pos;i++)r+=lower_bound(block+i*magic,block+i*magic+size[i],k)-block-i*magic;
	}
	return r;
}
int query(int x,int y,int k){
	int l=0,r=1e9+1e8,ans=0;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(count_(x,y,mid)>=k)r=mid;
		else l=mid;
	}
	return l;
}
int cmp(int a,int b){
	return a<b;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		magic=sqrt(n);int sz=n/magic;
		for(int i=1;i<=n;i++)scanf("%d",&A[i]),block[i]=A[i];
		for(int i=0;i<=sz;i++)size[i]=min(magic,n-magic*i);
		for(int i=0;i<=sz;i++)sort(block+i*magic,block+i*magic+size[i],cmp);
		while(m--){
			char s[2];
			scanf("%s",s);
			if(s[0]=='Q'){
				int x,y,z;
				scanf("%d%d%d",&x,&y,&z);
				printf("%d\n",query(x,y,z));
			}
			if(s[0]=='C'){
				int x,y;
				scanf("%d%d",&x,&y);
				update(x,y);
			}
		}
	}
	/*
	2
	7 3
	7 6 5 4 3 2 1
	*/
}


