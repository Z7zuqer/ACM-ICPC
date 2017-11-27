#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[100100],pre[100100];
pair<LL,int>r[100100];
void work(int n){
	LL t;
	scanf("%d",&t);
	int L=1,R=1,ansl=-1,ansr=-1;
	LL minv=1e18,nowsum=0;
	while(L<=R&&R<=n){
		nowsum+=r[R].first;
		while(L<R&&R<=n&&nowsum>t){
			L++;
			nowsum=r[R].first-r[L].first;
		}
		if(abs(nowsum-t)<abs(minv-t)){
			minv=nowsum;
			ansl=min(r[L].second,r[R].second);
			ansr=max(r[L].second,r[R].second);
		}
		R++;
	}
	printf("%lld %d %d\n",minv,ansl,ansr);
}
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		if(!n)break;
		for(int i=1;i<=n;i++)scanf("%lld",&A[i]),pre[i]=pre[i-1]+A[i];
		for(int i=1;i<=n;i++)r[i]={pre[i],i};
		sort(r+1,r+1+n);
		while(k--)work(n);
	}
}


