#include<bits/stdc++.h>
using namespace std;
const int maxn=200100;
vector<int>v[maxn];
double ans;
void DP(int rt,double res,int dep,int pre){
    int flg=0;
    for(int i=0;i<v[rt].size();i++){
        int e=v[rt][i];
        if(v[rt][i]==pre)continue;
        flg++;
    }
    if(flg==0)ans+=res*dep;
    else{
        double req=res/flg;
        for(int i=0;i<v[rt].size();i++){
            int e=v[rt][i];
            if(v[rt][i]==pre) continue;
            DP(e,req,dep+1,rt);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    DP(1,1.0,0,1);
    printf("%.12lf\n",ans);
}

