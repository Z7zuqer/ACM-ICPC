#include<bits/stdc++.h>
using namespace std;
#define LL long long
map<LL,LL>r;
map<LL,LL>mp;
LL po[110];
LL A[100100];
LL sum[100100],ans; 
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		cin>>A[i];
		sum[i]=sum[i-1]+A[i];
	}
	po[0]=1;
	for(int i=1;i<64;i++){
		po[i]=po[i-1]*k;
		if(po[i]>100000000000000)break;
	}
	mp[0]=1;
	for(int i=1;i<=n;i++){
		 r.clear();
		 for(int j=0;j<64;j++){
		 	if(r[po[j]]||!po[j])continue;
		 	r[po[j]]=1;
		 	ans+=mp[sum[i]-po[j]];
		 }
		 mp[sum[i]]+=1;
	}
	cout<<ans<<endl;
}


