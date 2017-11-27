#include<bits/stdc++.h>
using namespace std;
int A[100010],vis[100110];
vector<int>v[100010];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d%d",&A[i],&x);
		for(int j=1;j<=x;j++){
			int k;
			scanf("%d",&k);
			v[i].push_back(k);
		}
	}
	int pre=1,ans=0;
	for(int i=1;i<=n;i++){
		for(auto x:v[i]){
			vis[x]++;
			if(vis[x]==1)ans++;
		}
		while(A[i]-A[pre]>=86400){
			for(auto x:v[pre]){
				vis[x]--;
				if(vis[x]==0)ans--;
			}
			pre++;
		}
		printf("%d\n",ans);
	}
}
