#include<bits/stdc++.h>
using namespace std;
struct {
	int x,y;
}r[100100];
int n,vis[100100];
void place(int x,int y,int v,int k){
	for(int i=1;i<=n;i++)
		if(r[i].x<=x+k&&r[i].x>=x&&r[i].y>=y&&r[i].y<=y+k)	
			vis[i]+=v;
}
int dfs(int now,int k){
	int maxx=0,maxy=0,minx=1e9,miny=1e9;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		maxx=max(maxx,r[i].x);
		maxy=max(maxy,r[i].y);
		minx=min(minx,r[i].x);
		miny=min(miny,r[i].y);
		//cout<<i<<endl;
	}
	//cout<<maxx<<" "<<maxy<<" "<<minx<<" "<<miny<<endl;
	if(now==3)return (maxx-minx<=k)&&(maxy-miny<=k);
	place(minx,miny,1,k);
	if(dfs(now+1,k))return 1;
	place(minx,miny,-1,k);
	
	place(minx,maxy-k,1,k);
	if(dfs(now+1,k))return 1;
	place(minx,maxy-k,-1,k);
	
	place(maxx-k,miny,1,k);
	if(dfs(now+1,k))return 1;
	place(maxx-k,miny,-1,k);
	
	place(maxx-k,maxy-k,1,k);
	if(dfs(now+1,k))return 1;
	place(maxx-k,maxy-k,-1,k);
	
	return 0;
}
int check(int k){
	for(int i=1;i<=n;i++)vis[i]=0;
	return dfs(1,k);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&r[i].x,&r[i].y);
	int l=0,r=1e9;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
		//cout<<l<<" "<<r<<endl;
	}
	printf("%d\n",r);
}


