#include<bits/stdc++.h>
using namespace std;
vector<int>v[1000005];
int n,m,A[100005];
int main(){
	while(scanf("%d%d",&n,&m)==2){
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		for(int i=1;i<=n;i++)
			v[A[i]].push_back(i);
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&b,&a);
			if(b<=v[a].size())printf("%d\n",v[a][b-1]);
			else cout<<0<<endl;
		}
	}
}


