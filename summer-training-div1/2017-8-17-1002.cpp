#include<bits/stdc++.h>
using namespace std;
long long n,l,d[100100],v[100100];
long long gcd(long long a,long long b){
    return b ? gcd(b,a % b) : a;
}
struct Fraction{
    long long num;
    long long den;
    Fraction(long long num = 0,long long den = 1){
        if(den < 0){
            num = -num;
            den = -den;
        }
        assert(den != 0);
        long long g = gcd(abs(num),den);
        this->num = num / g;
        this->den = den / g;
    }
    Fraction operator + (const Fraction &o) const{
        return Fraction(num*o.den+den*o.num,den*o.den);
    }
    Fraction operator - (const Fraction &o) const{
        return Fraction(num*o.den-den*o.num,den*o.den);
    }
    Fraction operator * (const Fraction &o) const{
        return Fraction(num*o.num,den*o.den);
    }
    Fraction operator / (const Fraction &o) const{
        return Fraction(num*o.den,den*o.num);
    }
    bool operator < (const Fraction &o) const{
        return num*o.den < den*o.num;
    }
    bool operator == (const Fraction &o) const{
        return num*o.den == den*o.num;
    }
};
Fraction cal(int j,int k){
    Fraction dis(abs(d[j]-d[k]),1);
    Fraction vel(abs(v[j]-v[k]),1);
    return dis / vel;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&n,&l);
        for(int i=1;i<=n;i++)scanf("%lld",&d[i]);
        for(int i=1;i<=n;i++)scanf("%lld",&v[i]);
        if(v[n] < 0)
            for(int i = 1;i <= n;++i) v[i] *= -1, d[i] = l - d[i];

        for(int i = 1;i < n;++i)
            if(v[i] > v[n] && d[i] > d[n]) d[i] -= l;
            else if(v[i] < v[n] && d[i] < d[n]) d[i] += l;

        Fraction ans=Fraction(0,1);
        int pos = n;
        for(int i=n-1;i>=1;i--){
            if(v[i] < 0){
                if(pos == n){
                    ans = max(ans,cal(pos,i));
                    pos = i;
                }
                else{
                    if(!(cal(pos,i) < ans)){
                        ans = max(ans,cal(n,i));
                        pos = i;
                    }
                }
            }
            else{
                ans = max(ans,cal(n,i));
            }
        }

        printf("%lld/%lld\n",ans.num,ans.den);
    }
}
