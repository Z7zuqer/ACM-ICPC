#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
vector<int>v[maxn];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int prenum=5,prer=3;
	v[1].push_back(1*k);
	v[1].push_back(2*k);
	v[1].push_back(3*k);
	v[1].push_back(5*k);
	int maxv=5*k;
	for(int i=2;i<=n;i++){
		prenum+=2;
		v[i].push_back((prenum++)*k);
		v[i].push_back((prenum++)*k);
		v[i].push_back((prenum++)*k);
		v[i].push_back((++prenum)*k);
		maxv=max(maxv,prenum*k);
	}
	printf("%d\n",maxv);
	for(int i=1;i<=n;i++,puts(""))for(int j=0;j<4;j++)printf("%d ",v[i][j]);
}


