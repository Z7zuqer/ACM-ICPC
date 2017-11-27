#include<bits/stdc++.h>
using namespace std;
int d[100100],a[100100],n,m,vis[100100];
int order[100100],cnt;
int work(int k){
	if(k>n)k=n;cnt=0;
	for(int i=n;i>=1;i--)vis[i]=0;
	for(int i=k;i>=1;i--){
		if(!d[i])continue;
		if(!vis[d[i]])order[++cnt]=d[i];
		vis[d[i]]=1;
	}
	for(int i=1;i<=m;i++)vis[i]=0;
	int now=cnt,flg=0;
	for(int i=1;i<=k;i++){
		if(d[i]==0){
			if(!now)continue;
			vis[order[now]]++;
			if(vis[order[now]]>=a[order[now]])now--;
		}
		else if(vis[d[i]]==-1){
			if(!now)continue;
			vis[order[now]]++;
			if(vis[order[now]]>=a[order[now]])now--;
		}
		else if(vis[d[i]]<a[d[i]]){
			if(!now)continue;
			vis[order[now]]++;
			if(vis[order[now]]>=a[order[now]])now--; 
		}
		else if(vis[d[i]]>=a[d[i]])flg++,vis[d[i]]=-1;
	}
	//cout<<k<<" "<<flg<<endl;
	return flg>=m;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	int l=0,r=1e6;
	while(l<r){
		int mid=(l+r)>>1;
		if(work(mid))r=mid;
		else l=mid+1;
	}
	if(r>n)cout<<"-1"<<endl;
	else cout<<r<<endl;
}


