#include<bits/stdc++.h>
using namespace std;
int T,n,m;
vector<int>
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			v[b].push_back(a);
		}
		//必定是一条链 判断一下点的度数（一进一出，其他全是2度） 懒得写了 
	}
}


