#include<bits/stdc++.h>
using namespace std;
pair<int,int>r[5010];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int div=(int)(floor(m*1.5));
	for(int i=1;i<=n;i++)scanf("%d%d",&r[i].second,&r[i].first),r[i].second=-r[i].second;
	sort(r+1,r+1+n);
	int cnt=0,divs=r[n-div+1].first;
	for(int i=n;i>=1;i--){
		if(r[i].first<divs)break;
		cnt++;
		//printf("%d %d\n",r[i].second,r[i].first);
	}
	printf("%d %d\n",r[n-div+1].first,cnt);
	for(int i=n;i>=1;i--){
		if(r[i].first<divs)break;
		printf("%d %d\n",-r[i].second,r[i].first);
	}
}


