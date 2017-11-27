#include<bits/stdc++.h>
using namespace std;
struct {
	int l,r;
}X[110],Y[110];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m,x,y;
		scanf("%d%d%d%d",&n,&m,&x,&y);
		for(int i=1;i<=x;i++)
			scanf("%d%d",&X[i].l,&X[i].r);
		for(int i=1;i<=y;i++)
			scanf("%d%d",&Y[i].l,&Y[i].r);
		int ans=0;
		for(int i=1;i<=x;i++)
			for(int j=1;j<=y;j++){
				int l=max(X[i].l,Y[j].l);
				int r=min(X[i].r,Y[j].r);
				if(l>r)continue;
				int rem=r-l+1;
				if(rem<m)continue;
				ans+=rem-m+1; 
			}
		cout<<ans<<endl;
	}
}


