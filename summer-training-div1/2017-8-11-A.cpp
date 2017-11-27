#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}r[1010];
int mp[1010][1010],pre[1010][1010];
int cmp(node m,node n){
	return m.x<n.x;
}
void work(int L,int R){
	if(L>R)return ;
	int mid=(L+R)>>1;
	for(int i=L;i<=R;i++)mp[r[mid].x][r[i].y]=1;
	work(L,mid-1);
	work(mid+1,R);
}
vector<pair<int,int> >v;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&r[i].x,&r[i].y);
	for(int i=1;i<=n;i++)pre[r[i].x][r[i].y]=1;
	sort(r+1,r+1+n,cmp);
	work(1,n);
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++)
			if(mp[i][j]!=pre[i][j])
				v.push_back({i,j});
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++)printf("%d %d\n",v[i].first,v[i].second);
}
