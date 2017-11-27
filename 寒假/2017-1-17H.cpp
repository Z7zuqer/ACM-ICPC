#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL mod=1e9+7;
map<LL,LL>mp;
LL B[10]={1,2,4,5};
LL F(LL x){
	if(mp[x]>0)return mp[x];
	if(x<2)return mp[x]=B[x];
	return mp[x]=((F((x-1)/2)+F((x-2)/2))%mod+F(x/2))%mod;
}
int main(){
	LL n;
	cin>>n;
	cout<<F(n)<<endl;
}
//OEIS



