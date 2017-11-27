#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll myPow(ll x,ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * x;
        x = x * x;
        n >>= 1;
    }
    return res;
}
int n,m,mp[55][55];
ll ans;
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= m;++j)
			scanf("%d",&mp[i][j]);
	for(int i = 1;i <= n;++i){
		int cnt = 0;
		for(int j = 1;j <= m;++j)
			if(mp[i][j] == 1) cnt++;
		ans += myPow(2,cnt) + myPow(2,m-cnt) - m - 2;
	}
	for(int j = 1;j <= m;++j){
		int cnt = 0;
		for(int i = 1;i <= n;++i)
			if(mp[i][j] == 1) cnt++;
		ans += myPow(2,cnt) + myPow(2,n-cnt) - n - 2;
	}
	for(int i1 = 1;i1 <= n;++i1)
		for(int i2 = i1 + 1;i2 <= n;++i2)
			for(int j1 = 1;j1 <= m;++j1)
				for(int j2 = j1 + 1;j2 <= m;++j2)
					if(mp[i1][j1] == mp[i1][j2] && mp[i1][j2] == mp[i2][j1] && mp[i2][j1] == mp[i2][j2]) ans++;
	ans += n*m;
	cout << ans;
	
	return 0;
} 

