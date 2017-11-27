#include<bits/stdc++.h>
using namespace std;
long long r[1000010],c[1000010];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		long long sum=0;
		for(int i=1;i<=n;i++)cin>>r[i],sum+=r[i];
		sum/=n;
		c[0]=0;
		for(int i=1;i<n;i++)c[i]=c[i-1]+r[i]-sum;
		sort(c,c+n);
		long long k=c[n/2];
		long long ans=0;
		for(int i=0;i<n;i++)ans+=abs(k-c[i]);
		cout<<ans<<endl;
	}
}
