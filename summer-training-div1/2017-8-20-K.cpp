#include<bits/stdc++.h>
using namespace std;

int v[11][11],ans[11];

bool check(int x,int n){
    ans[n] = x;
    for(int i=1;i<=n;i++)if(1+(ans[i]*ans[n]-1)%9!=v[i][n])return 0;
    for(int i=1;i<=n;i++)if(1+(ans[i]*ans[n]-1)%9!=v[n][i])return 0;
    return 1;
}

int main(){
    for(int i = 1;i <= 9;++i)
        for(int j = 1;j <= 9;++j)
            scanf("%d",&v[i][j]);
    for(int k1 = 1;k1 <= 9;++k1) if(check(k1,1))
    for(int k2 = 1;k2 <= 9;++k2) if(check(k2,2))
    for(int k3 = 1;k3 <= 9;++k3) if(check(k3,3))
    for(int k4 = 1;k4 <= 9;++k4) if(check(k4,4))
    for(int k5 = 1;k5 <= 9;++k5) if(check(k5,5))
    for(int k6 = 1;k6 <= 9;++k6) if(check(k6,6))
    for(int k7 = 1;k7 <= 9;++k7) if(check(k7,7))
    for(int k8 = 1;k8 <= 9;++k8) if(check(k8,8))
    for(int k9 = 1;k9 <= 9;++k9) if(check(k9,9)){
        for(int j = 1;j <= 9;++j)
            printf("%d ",9*(j-1)+ans[j]);
        return 0;
    }
    cout << "No solution";

    return 0;
}

