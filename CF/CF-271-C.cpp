#include<bits/stdc++.h>
using namespace std;
int X[5][5],Y[5][5];
int A[5],B[5],ans;
map<pair<int,int>,int>mp[5];
int newX(int x,int y,int a,int b){
	return a-(y-b);
}
int newY(int x,int y,int a,int b){
	return b+(x-a);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int times=1;times<=n;times++){
		for(int i=1;i<=4;i++)mp[i].clear();
		ans=1e9+1;
		for(int i=1;i<=4;i++)scanf("%d%d%d%d",&X[i][1],&Y[i][1],&A[i],&B[i]);
		for(int i=1;i<=4;i++){
			mp[i][{X[i][1],Y[i][1]}]=1;
			for(int j=2;j<=4;j++){
				X[i][j]=newX(X[i][j-1],Y[i][j-1],A[i],B[i]);
				Y[i][j]=newY(X[i][j-1],Y[i][j-1],A[i],B[i]);
				if(mp[i][{X[i][j],Y[i][j]}])mp[i][{X[i][j],Y[i][j]}]=min(mp[i][{X[i][j],Y[i][j]}],j);
				else mp[i][{X[i][j],Y[i][j]}]=j;
			}
		}
		for(int i=1;i<=4;i++){
			for(int j=1;j<=4;j++){
				for(int k=-10000;k<=10000;k++){
					for(int u=1;u<=4;u++){
						if(u!=i&&Y[i][j]!=k&&mp[u][{X[i][j],k}]){
							//X i j Y i j 
							int res=abs(k-Y[i][j]);
							if(mp[u][{X[i][j]+res,k}]&&mp[u][{X[i][j]+res,Y[i][j]}])ans=min(ans,mp[u][{X[i][j]+res,k}]+mp[u][{X[i][j]+res,Y[i][j]}]+mp[u][{X[i][j],k}]+mp[u][{X[i][j],Y[i][j]}]-4);
							if(mp[u][{X[i][j]-res,k}]&&mp[u][{X[i][j]-res,Y[i][j]}])ans=min(ans,mp[u][{X[i][j]-res,k}]+mp[u][{X[i][j]-res,Y[i][j]}]+mp[u][{X[i][j],k}]+mp[u][{X[i][j],Y[i][j]}]-4);
							cout<<X[i][j]<<" "<<Y[i][j]<<"==="<<X[i][j]<<" "<<k<<" "<<ans<<endl;
						}	
					}
				}
				for(int k=-10000;k<=10000;k++){
					int sta
					for(int u=1;u<=4;u++){
						if(u!=i&&X[i][j]!=k&&mp[u][{k,Y[i][j]}]){
							//X i j Y i j 
							int res=abs(k-X[i][j]);
							if(mp[u][{k,Y[i][j]+res}]&&mp[u][{X[i][j],Y[i][j]+res}])ans=min(ans,mp[u][{k,Y[i][j]+res}]+mp[u][{X[i][j],Y[i][j]+res}]+mp[u][{k,Y[i][j]}]+mp[u][{X[i][j],Y[i][j]}]-4);
							if(mp[u][{k,Y[i][j]-res}]&&mp[u][{X[i][j],Y[i][j]-res}])ans=min(ans,mp[u][{k,Y[i][j]-res}]+mp[u][{X[i][j],Y[i][j]-res}]+mp[u][{k,Y[i][j]}]+mp[u][{X[i][j],Y[i][j]}]-4);
						}
					}
				}
			}
		}
		printf("%d\n",(ans==1e9+1)?-1:ans);
	}
}
/*
1
1 1 0 0
-2 1 0 0
-1 1 0 0
1 -1 0 0
*/

