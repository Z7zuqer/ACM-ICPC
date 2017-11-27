#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int seq[maxn],c[maxn];
long long ave,sum;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&seq[i]);
		sum+=seq[i];
	}
	ave=sum/n;
	for(int i=2;i<=n;i++){
		c[i]=seq[i]+c[i-1]-ave;
	}
	sort(c+1,c+1+n);
	long long res,ans=0;
	if(n%2)res=c[n/2+1];
	else res=(c[n/2]+c[n/2+1])/2;
	for(int i=1;i<=n;i++){
		ans+=abs(res-c[i]);
	}
	cout<<ans<<endl;
}
