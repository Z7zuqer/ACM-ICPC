#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n;
int a[maxn],dp[maxn],b[maxn];
int cnt,maxm;
int find(int k){
	int l=1,r=cnt,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(b[mid]>k)l=mid+1,ans=mid;
		else r=mid-1;//,ans=mid;
	}
	return ans;
}
void pre(){
	for(int i=n;i>=1;i--){
		int pos=find(a[i]);
		dp[i]=pos+1;
		cnt=max(cnt,pos+1);
		b[pos+1]=a[i];
	}
}
void work(int k){
	int lst=-0x7fffff;
	for(int i=1;i<=n;i++){
		if(dp[i]>=k&&a[i]>lst){
			k--;
			if(k)printf("%d ",a[i]);
			else printf("%d\n",a[i]);
			lst=a[i];
			if(!k){
				//cout<<endl;
				return ;
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	pre();
	int t,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);
		if(k<=cnt)work(k);
		else cout<<"Impossible"<<endl;
	}
}
