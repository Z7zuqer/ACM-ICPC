#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int k,n;
double k_1;

double ksm(int x)
{
    if(x==1)return k_1;
    double tmp=ksm(x/2);
    tmp*=tmp;
    if(x%2)tmp*=k_1;
    return tmp;
}

double ans1(int m)
{
    double tmp1=ksm(m);
    double ans1=(1-tmp1)/(k-1);
    return ans1;
}

double ans2(int m)
{
    if(m==0)return 0;
    double tmp2=(m-ans1(m))/(k-1);
    tmp2*=2;
    return tmp2;
}

int main(){
    cin>>n>>k;
    k_1=1.0/k;
    int tm=(2*n-3)/2;
    int m=tm/2;
    double ans=ans2(m);
    if(tm%2)ans+=ans1(m+1);
    ans*=2;
    ans+=ans1(m+1);
    ans+=n;
    printf("%.7lf",ans);
    return 0;
}
