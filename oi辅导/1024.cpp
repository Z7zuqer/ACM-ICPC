#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
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
	int n;
	scanf("%d",&n);
	int ans=1;
	pre();
	for(int i=0;i<num_pri;i++){
		int cnt=0;
		while(n%pri[i]==0){
			cnt++;
			n/=pri[i];
		}
		if(cnt)ans*=(cnt+1);
		if(n==1)break;
	}
	if(n>1)ans*=2;
	printf("%d\n",ans);
}


