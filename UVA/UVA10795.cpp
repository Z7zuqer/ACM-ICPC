#include<bits/stdc++.h>
using namespace std;
long long f(int p[],int wh,int final){
	if(wh==0)return 0;
	if(p[wh]==final)return f(p,wh-1,final);
	return f(p,wh-1,6-final-p[wh])+(1LL<<(wh-1));
}
int main(){
	int sta[61],lst[61];
	int n,cas=1;
	while(scanf("%d",&n)==1&&n){
		int k=n;
		long long ans=0;
		for(int i=1;i<=n;i++)scanf("%d",&sta[i]);
		for(int i=1;i<=n;i++)scanf("%d",&lst[i]);
		while(k&&sta[k]==lst[k])k--;
		if(k){
			ans=f(sta,k-1,6-sta[k]-lst[k])+1+f(lst,k-1,6-sta[k]-lst[k]);
		}
		printf("Case %d: %lld\n",cas++,ans);
	}
}
