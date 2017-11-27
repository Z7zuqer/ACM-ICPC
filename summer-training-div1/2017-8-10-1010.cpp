include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <ctime>
#include <cmath>
using namespace std;
const int maxn=2000+5;
int father[maxn];
int vis[maxn];
vector<int>g[maxn];

int du[maxn],n;

int toposort()
{
    memset(du,0,sizeof(du));
    memset(vis,0,sizeof(vis));
    int ans=0;
    for(int i=1;i<=n;i++)
    {
    for(int j=0;j<g[i].size();j++)
    {
        du[i]++;
    }
    }
    queue<int>Q;
    for(int i=1;i<=n;i++)
    {
    if(!du[i])
    {
        Q.push(i);
    }
    }
    while(!Q.empty())
    {
    int x=Q.front();
    Q.pop();
    int t=father[father[x]];
//    printf("x=%d t=%d\n",x,t);
    if(father[x]!=-1&&!vis[x]&&!vis[father[x]])
    {
        du[t]--;
        vis[x]=1;
        vis[father[x]]=1;
        ans++;
    }
    else
    {
        return -1;
    }
    if(!du[t])
    Q.push(t);
    
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
    for(int i=0;i<maxn;i++)
        g[i].clear();
    memset(father,-1,sizeof(father));
    int k;
    scanf("%d%d",&n,&k);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&father[i]);
        g[father[i]].push_back(i);
    }
    int ans=toposort();
//    printf("!  %d\n",ans-1);
    if(ans==-1||ans-1>k)
        printf("Alice\n");
    else
        printf("Bob\n");
    }
}

