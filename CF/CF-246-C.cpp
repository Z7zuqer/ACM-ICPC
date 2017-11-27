#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int pri[maxn],isnotpri[maxn]={1,1},num_pri;
int pos[maxn],A[maxn];
vector<pair<int,int> >v;
int main(){
	for(int i=2;i<maxn;i++){
		if(!isnotpri[i])pri[num_pri++]=i;
		for(int j=0;j<num_pri&&pri[j]*i<maxn;j++){
			isnotpri[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),pos[A[i]]=i;
	for(int i=1;i<=n;i++){
		if(pos[i]==i)continue;
		while(1){
			if(pos[i]==i)break;
			for(int j=i;j<pos[i];j++){
				if(!isnotpri[pos[i]-j+1]){
					v.push_back({j,pos[i]});
					swap(A[j],A[pos[i]]);
					swap(pos[A[j]],pos[A[pos[i]]]);
				}
			}
		}
	}
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++)printf("%d %d\n",v[i].first,v[i].second);
}
