#include<bits/stdc++.h>
using namespace std;
int vis[1000000+107];
int A[1000000+107];
vector<int>v;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		vis[A[i]]=1;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		int rem=1e6-A[i]+1;
		if(!vis[rem])v.push_back(rem);
		else cnt++;
	}
	for(int i=1;i<=1e6&&cnt/2>0;i++){
		if(!vis[i]&&!vis[1000001-i]){
			vis[i]=vis[1000001-i]=1;
			cnt-=2;
			v.push_back(i);
			v.push_back(1000001-i);
		}
	}
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++){
		printf("%d ",v[i]);
	}
}


