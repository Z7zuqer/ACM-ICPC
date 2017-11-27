#include<bits/stdc++.h>
using namespace std;
const int maxn=100003;
int n,A[maxn],cnt;
vector<int>ans[maxn];
multiset<pair<int,int> >s;
void init(){
	cnt=0;s.clear();
	for(int i=1;i<=n;i++)ans[i].clear();
}
int main(){
	int T,cas=1;
	scanf("%d",&T);
	multiset<pair<int,int> >::iterator it;
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&A[i]);
			it=s.upper_bound({A[i],n});
			if(it==s.begin()||(it==s.end()&&!s.size())){
				s.insert({A[i],i});
				s.insert({A[i],i});
				ans[i].push_back(i);cnt++;
			}
			else {
				--it;
				ans[(*it).second].push_back(i);
				s.insert({A[i],(*it).second});
				s.insert({A[i],(*it).second});
				s.erase(it);
			}
		}
		printf("%d\n",cnt);
		for(int i=1;i<=n;i++)
			if(ans[i].size()){
				printf("%d ",ans[i].size());
				for(int j=0;j<ans[i].size();j++)
					if(j!=ans[i].size()-1)printf("%d ",ans[i][j]);
					else printf("%d\n",ans[i][j]);
				//printf("\n");
			}
	}
}


