#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int cnt[1000010];
long long ans;
struct {
	int k;
	vector<int>v;
}a[100010];
long long fac(int k){
	long long res=1;
	for(int i=2;i<=k;i++)res=(res*(long long)i+mod)%mod;
	return res;
}
map<int,int>mp;
map<int,int>::iterator it;
int main(){
	//cout<<qpow(4)<<endl;
	int n,m,num=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].k);
		for(int j=0;j<a[i].k;j++){
			int x;
			scanf("%d",&x);
			a[i].v.push_back(x);
			cnt[x]++;
			if(cnt[x]==1)num++;
		}
	}
	ans=1;
	for(int i=1;i<=n;i++){
		mp.clear();
		set.clear();
		for(int j=0;j<a[i].v.size();j++){
			mp[cnt[a[i].v[j]]]++;
		}
		int tmp=1;
		for(it=mp.begin();it!=mp.end();it++)ans=(ans*fac(it->second)+mod)%mod;
		
	}
	cout<<ans<<endl;
}
