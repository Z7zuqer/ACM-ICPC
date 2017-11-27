#include<bits/stdc++.h>
using namespace std;
int r[1010],c[1010];
vector<int>R,C;
int main(){
	int m,n,k,l,d;
	scanf("%d%d%d%d%d",&n,&m,&k,&l,&d);
	for(int i=1;i<=d;i++){
		int x,y,p,q;
		scanf("%d%d%d%d",&x,&y,&p,&q);
		if(abs(x-p)==1)r[min(x,p)+1]++;
		if(abs(y-q)==1)c[min(y,q)+1]++;
	}
	int ans=d;
	for(int i=1;i<=l;i++){
		int maxv=-1,idx=-1;
		for(int j=2;j<=m;j++)
			if(maxv<c[j]){
				maxv=c[j];
				idx=j;
			}
		if(maxv==0)break;
		ans-=maxv;
		c[idx]=0;
		C.push_back(idx);
	}
	for(int i=1;i<=k;i++){
		int maxv=-1,idx=-1;
		for(int j=2;j<=n;j++){
			if(maxv<r[j]){
				maxv=r[j];
				idx=j;
			}
		}
		if(maxv==0)break;
		ans-=maxv;
		r[idx]=0;
		R.push_back(idx);
	}
	sort(R.begin(),R.end());
	sort(C.begin(),C.end());
	//printf("%d\n",R.size());
	for(auto i:R)printf("%d ",i-1);puts("");
	//printf("%d\n",C.size());
	for(auto i:C)printf("%d ",i-1);puts("");
}


