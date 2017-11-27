#include<bits/stdc++.h>
using namespace std;
int r[100010],cnt[100010];
int le[100010],ri[100010],n;
int check(int k){
	int x=r[1],y=k-r[1];
	le[1]=x;ri[1]=0;
	for(int i=2;i<=n;i++){
		if(i%2==0){
			le[i]=min(x-le[i-1],r[i]);
			ri[i]=r[i]-le[i];
		}
		else {
			ri[i]=min(y-ri[i-1],r[i]);
			le[i]=r[i]-ri[i];
		}
	}
	return le[n]==0;
}
int main(){
	//int n;
	while(scanf("%d",&n)==1&&n){
		int mx=-1;
		for(int i=1;i<=n;i++)
			scanf("%d",&r[i]),mx=max(mx,r[i]);
		if(n==1){
			cout<<r[1]<<endl;
			continue;
		}
		r[0]=r[n];
		int maxm=-1;
		for(int i=1;i<=n;i++)maxm=max(maxm,r[i]+r[i-1]);
		if(n%2==0)cout<<maxm<<endl;
		else {
			int l=maxm,rr=mx*3;
			while(l<rr){
				int mid=(l+rr)/2;
				if(check(mid))rr=mid;
				else l=mid+1;
			}
			cout<<rr<<endl;
		}
	}
}
