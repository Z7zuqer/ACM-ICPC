#include<bits/stdc++.h>
using namespace std;
int A[210];
int vis[2010],B[210],cnt[2010];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),B[i]=A[i],cnt[1000+A[i]]++;
	sort(B+1,B+1+n,greater<int>());
	//cout<<B[1]<<endl;
	int maxm=-1e9;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			vector<int>v;
			memset(vis,0,sizeof vis);
			for(int u=i;u<=j;u++)
				v.push_back(A[u]),vis[1000+A[u]]++;
			sort(v.begin(),v.end());
			int now=1,nowv=0,tmp=0;
			for(int u=1;now<=n&&nowv<v.size()&&u<=k;){
				if(vis[1000+B[now]]<cnt[1000+B[now]]){
					if(B[now]<=v[nowv])break;
					else {
						vis[1000+B[now]]++;
						tmp+=B[now];
						now++;
						nowv++;
						u++;
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


