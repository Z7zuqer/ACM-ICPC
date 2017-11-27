#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=1e7+7;
int pri[maxn],isnotpri[maxn]={1,1},num_pri;
void pre(){
	for(int i=2;i<maxn;i++){
		if(!isnotpri[i])pri[num_pri++]=i;
		for(int j=0;j<num_pri&&1.0*pri[j]*i<maxn;j++){
			isnotpri[pri[j]*i]=1;
			if(i%pri[j]==0)break;
		}
	}
}
int main(){
	LL n,m;
	scanf("%lld%lld",&n,&m);
	pre();
	for(int i=0;i<num_pri;i++){
		if(n%pri[i]==0&&m%pri[i]==0){
			while(n%pri[i]==0)n/=pri[i];
			while(m%pri[i]==0)m/=pri[i];
		}
		if(n==m)return 0*printf("Yes");
	}
	if(m!=1)puts("No");
	else puts("Yes");
}


