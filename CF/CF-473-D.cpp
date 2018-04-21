#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int pri[maxn*30],isnotpri[maxn*30],num_pri,vis[maxn*30];
int A[maxn];
void pre(){
	for(int i=2;i<maxn*30;i++){
		if(!isnotpri[i])pri[num_pri++]=i;
		for(int j=0;j<num_pri&&pri[j]*i<maxn*30;j++){
			isnotpri[pri[j]*i]=1;
			if(i%pri[j]==0)break;
		}
	}
}
int main(){
	pre();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	int sta=n+1;
	for(int i=1;i<=n;i++){
		int flg=0,x=A[i];
		vector<int>v;
		for(int j=0;j<num_pri;j++){
			if(x%pri[j]==0){
				if(vis[pri[j]]){
					flg=1;
					break;
				}
				else v.push_back(pri[j]);
				while(x%pri[j]==0)x/=pri[j];
				if(x==1)break;
			}
		}
		if(!flg)
			for(int j=0;j<v.size();j++)
				vis[v[j]]++;
		else {
			sta=i;
			break;
		}
	}
	for(int i=1;i<=sta-1;i++)printf("%d ",A[i]);	
	int now=0;
	for(int i=sta;i<=n;i++){
		while(now<num_pri&&vis[pri[now]])now++;
		printf("%d ",pri[now++]);
	}
}


