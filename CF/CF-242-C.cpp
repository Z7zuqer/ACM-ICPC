#include<bits/stdc++.h>
using namespace std;
int A[210];
int vis[2010],B[210];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),B[i]=A[i];
	sort(B+1,B+1+n,greater<int>());
	int maxm=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			vector<int>v;
			memset(vis,0,sizeof vis);
			for(int u=i;u<=j;u++)
				v.push_back(A[u]),vis[1000+A[k]]=1;
			sort(A.begin(),A.end());
			int now=1,nowv=0,tmp=0;
			for(int u=1;now<=n&&nowv<v.size()&&u<=k;u++){
				if(!vis[B[now]]){
					if(B[now]<=v[nowv])break;
					else {
						tmp+=B[now];
						now++;
						nowv++;
					}
				}
				else now++;
			}
			for(;nowv<v.size();nowv++)tmp+=v[nowv];
			maxm=max(maxm,tmp);
		}
	}
	printf("%d\n",maxm);
}


