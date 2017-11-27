#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,k,p;
LL A[2010],B[2010],vis[2010];
LL cal(int i,int j){
	return abs(A[i]-B[j])+abs(p-B[j]);
}
int check(LL r){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		int flg=0;
		for(int j=1;j<=k;j++){
			if(vis[j])continue;
			if(cal(i,j)<=r){
				flg=1;
				vis[j]=1;
				break;
			}
		}
		if(!flg)return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d%d",&n,&k,&p);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=k;i++)scanf("%d",&B[i]);
	sort(A+1,A+1+n);
	sort(B+1,B+1+k);
	LL l=0,r=2e9+7;
	while(l<r){
		LL mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<r<<endl;
}


