#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,int> >v;
vector<vector<pair<int,int> > >ans;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	int sum=0;
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=1;j<=m;j++){
				sum++;v.push_back({i,j});
				if(sum>=2&&k>1){
					ans.push_back(v);
					v.clear();
					sum=0;
					k--;
				}
			}
		}
		else {
			for(int j=m;j>=1;j--){
				sum++;v.push_back({i,j});
				if(sum>=2&&k>1){
					ans.push_back(v);
					v.clear();
					sum=0;
					k--;
				}
			}
		}
	}
	if(sum>0)ans.push_back(v);
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i].size());
		for(int j=0;j<ans[i].size();j++)
			printf("%d %d ",ans[i][j].first,ans[i][j].second);
		puts("");
	}
}


