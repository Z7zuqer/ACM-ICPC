#include<bits/stdc++.h>
using namespace std;
int a[100100];
long long cnt[100100];
int main(){
	int n;
	//cout<<(1^2)<<endl; 
	//cout<<(2^5)<<" "<<(7^5)<<endl;
	int x;
	scanf("%d%d",&n,&x);

	for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
	long long ans=0;
	for(int i=1;i<=100001;i++){
		if(!cnt[i])continue;//cout<<(x^i)<<endl;
		if(x==0)ans+=cnt[i]*(cnt[i]-1)/2,cnt[i]=0;
		if((x^i)>100000||(x^i)<1)continue;//cout<<"dsa"<<endl;
		if(x!=0)ans+=cnt[x^i]*cnt[i];cnt[x^i]=0;cnt[i]=0;//cout<<ans<<endl;
	}
	cout<<ans<<endl;
} 
