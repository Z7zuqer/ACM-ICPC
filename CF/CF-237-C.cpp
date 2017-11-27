#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
vector<int>v[maxn];
vector<pair<int,int> >ans;
int main(){
	//freopen("C://Users//Duhao//Desktop//input","r",stdin);
	int n,k,rt=-1,maxm=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		v[x].push_back(i);
		maxm=max(maxm,x);
	}
	if(v[0].size()!=1)return 0*printf("-1\n");
	if(v[1].size()>k)return 0*printf("-1\n");
	for(int i=0;i<v[1].size();i++)ans.push_back({v[0][0],v[1][i]});
	for(int now=2;now<=maxm;now++){
		if(v[now].size()*1LL>1LL*v[now-1].size()*(k-1))return 0*printf("-1\n");
		int now_num=v[now].size();
		for(int i=0;i<v[now-1].size()&&now_num>=1;i++)
			for(int j=0;j<k-1&&now_num>=1;j++)
				if(now_num>=1)ans.push_back({v[now-1][i],v[now][now_num-1]}),now_num--;
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d %d\n",ans[i].first,ans[i].second);
}


