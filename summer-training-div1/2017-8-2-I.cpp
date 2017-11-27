#include<bits/stdc++.h>
using namespace std;

const int maxn = 10000100;
const unsigned int xxx = 2147483647,inf = 4294967295;
int l[maxn],r[maxn],id[maxn],tot,sz;
unsigned int A[maxn],bmn[maxn],bpos[maxn],gmn,gpos,pw = 1,ans;
unsigned int x0,x1,a,b,c;
int n,q;

unsigned int nxt(){
    unsigned int t = x0 * a + x1 * b + c;
    x0 = x1;
    x1 = t;
    return x0 >> 2;
}

int main(){ 
    cin >> n >> q >> x0 >> x1 >> a >> b >> c;
    for(int i = 1;i <= n;++i) A[i] = xxx;
    sz = sqrt(n);
    tot = n / sz;
    if(n % sz) tot++;
    for(int i = 1;i <= tot;++i)
        l[i] = (i-1)*sz + 1, r[i] = i*sz;
    r[tot] = n;
    for(int i = 1;i <= n;++i)
        id[i] = (i-1) / sz + 1;
    for(int i = 1;i <= tot;++i)
        bmn[i] = xxx, bpos[i] = l[i];
    gmn = xxx; gpos = 1;


    for(int i = 1;i <= q;++i){
        pw *= 10099;
        unsigned int t = nxt() % unsigned(n);
        unsigned int x = nxt();
        A[t] = x;
        int bel = id[t];
        int lft = l[bel], rgt = r[bel];
        if(t == bpos[bel]){
            bmn[bel] = inf;
            for(int j = lft;j <= rgt;++j){
                if(A[j] < bmn[bel]){
                    bmn[bel] = A[j];
                    bpos[bel] = j;
                }
            }
        }
        else if(x < bmn[bel]){
            bmn[bel] = x;
            bpos[bel] = t;
        }
        if(t == gpos){
            gmn = inf;
            for(int j = 1;j <= tot;++j){
                if(bmn[j] < gmn){
                    gmn = bmn[j];
                    gpos = bpos[j];
                }
            }
        }
        else if(x < gmn){
            gmn = x;
            gpos = t;
        }
        ans += gmn * pw;
    }
    cout << ans << endl;

    return 0;
}
