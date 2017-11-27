#include<bits/stdc++.h>
using namespace std;
int A[510];
int mp[510][510]; 
int main(){
	int n,m;
	memset(mp,-1,sizeof mp);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		mp[a][b]=mp[b][a]=c;
	}
	double ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(mp[i][j]==-1)continue;
			ans=max(ans,(A[i]+A[j]*1.0)/mp[i][j]*1.0);
		}
	}
	printf("%.12lf\n",ans);
}


