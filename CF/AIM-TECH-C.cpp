#include<bits/stdc++.h>
using namespace std;
int n,A[100100],B[100100];
int find(int x){
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(B[mid]==x)return mid;
		else if(B[mid]>x)r=mid-1;
		else l=mid+1;
	}
	return -1;
}
vector<int>v[100100];
vector<int>res;
int vis[100100];
int main(){
	//int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),B[i]=A[i];
	sort(B+1,B+1+n);
	for(int i=1;i<=n;i++)A[i]=find(A[i]);
	//int now=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		res.clear();
		if(vis[i])continue;
		int now=A[i];
		res.push_back(i);
		while(now!=i){
			//cout<<now<<" "<<i<<endl;
			vis[now]=1;
			res.push_back(now);
			now=A[now];
		}
		v[++ans]=res;
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++){
		printf("%d ",v[i].size());
		sort(v[i].begin(),v[i].end());
		for(int j=0;j<v[i].size();j++)printf("%d ",v[i][j]);
		printf("\n");
	}
}


