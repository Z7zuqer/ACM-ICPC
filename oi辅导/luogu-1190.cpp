#include<bits/stdc++.h>
using namespace std;
int r[110];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	queue<int>q;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		q.push(x);
	}
	for(int i=1;i<=m;i++){
		r[i]=q.front();
		q.pop();
	}
	int ans=0;
	while(1){
		int minv=1e9,maxv=0;
		for(int i=1;i<=m;i++){
			maxv=max(maxv,r[i]);
			if(r[i]>0)minv=min(minv,r[i]);
		}
		if(maxv<=0)break;
		ans+=minv;
		for(int i=1;i<=m;i++){
			r[i]-=minv;
			if(r[i]==0){
				if(q.empty())continue;
				r[i]=q.front();
				q.pop();
			}
		}
	}
	printf("%d\n",ans);
}


