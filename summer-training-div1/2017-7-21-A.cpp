#include<bits/stdc++.h>
using namespace std;

int c,l,cnt,mx;
bool vis[100100];
int edNode[100100],diam[100100];
vector<vector<int> > G(100100);

void dfs1(int v,int d,int k){
    vis[v] = 1;
    if(d >= mx){
        mx = d;
        edNode[k] = v;
    }
    for(int i = 0;i < G[v].size();++i){
        if(vis[G[v][i]]) continue;
        dfs1(G[v][i],d+1,k);
    }
}

void dfs2(int v,int pre,int d,int k){
    diam[k] = max(diam[k],d);
    for(int i = 0;i < G[v].size();++i){
        if(G[v][i] == pre) continue;
        dfs2(G[v][i],v,d+1,k);
    }
}
/*
9 7
1 2 1 3 2 4
5 6 6 8 5 7 7 9
*/
int main(){
    cin >> c >> l;
    for(int i = 0;i < l;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 0;i < c;++i)
        if(!vis[i]){
            mx = 0;
            dfs1(i,0,++cnt);
        }
    for(int i = 1;i <= cnt;++i)
        dfs2(edNode[i],-1,0,i);
    sort(diam+1,diam+1+cnt);
    cout << (1+diam[cnt])/2 + (1+diam[cnt-1])/2 + 1;
}
