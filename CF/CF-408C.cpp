#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5*3+107;
int A[maxn];
multiset<int>s;
vector<int>v[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),s.insert(A[i]);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int ans=2e9+1;
	for(int i=1;i<=n;i++){
		int k=A[i];
		s.erase(s.find(k));
		for(int j=0;j<v[i].size();j++){
			s.erase(s.find(A[v[i][j]]));
			k=max(k,A[v[i][j]]+1);			
		}
		if(s.size())k=max(k,(*s.rbegin())+2);
		s.insert(A[i]);
		for(int j=0;j<v[i].size();j++){
			s.insert(A[v[i][j]]);
		}
		ans=min(ans,k);
	}
	cout<<ans<<endl;
}















