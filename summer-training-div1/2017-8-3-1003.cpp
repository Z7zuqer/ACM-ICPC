#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int T;
ll l,r,k,rem[1000100];
bool notPrime[1000100];
vector<ll> p;
vector<vector<ll> > cnt(1000100);

void init(){
    int m = sqrt(1000000+0.5);
    for(int i = 2;i <= m;++i) if(!notPrime[i])
        for(int j = i*i;j <= 1000000;j += i) notPrime[j] = 1;
    for(int i = 2;i <= 1000000;++i)
        if(!notPrime[i]) p.emplace_back(i);
}

int main(){
    init();
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        ll ans = 0,rrr=r-l;
        cin >> l >> r >> k;
        for(int i = 0;i <= rrr;++i) cnt[i].clear();
        for(int i = 0;i <= rrr;++i) rem[i] = l + i;
        for(auto x: p){
        	int kkk=r/x;
            for(ll i = (l+x-1) / x;i <= kkk;++i){
                ll t = i * x;
                ll A = t;
                ll tmp = 0;
                while(t % x == 0){
                    tmp++;
                    t /= x;
                    rem[A-l] /= x;
                }
                cnt[A-l].emplace_back(tmp);
            }
        }
        for(int i = 0;i <= rrr;++i)
            if(rem[i] > 1) cnt[i].emplace_back(1);
        for(int i = 0;i <= rrr;++i){
            int tmp = 1;
            for(int j = 0;j < cnt[i].size();++j)
//                cout << i + l << " : " << cnt[i][j] << endl;
                tmp = (tmp * (cnt[i][j]*k%MOD + 1)) % MOD;
            //ans = (ans + tmp) % MOD;
            ans=(ans+tmp)%MOD;
        }
        cout << ans << endl;
    }

    return 0;
}
