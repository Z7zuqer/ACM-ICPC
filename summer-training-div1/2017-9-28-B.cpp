#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstdlib>
using namespace std;
typedef long long ll;
const int N=1010;
const int M=20010;
const int inf=100000000;
int Case,n,m,K,i,j,x,y,g[N],v[M],nxt[M],ed,vis[N],col[N],pos;
 
inline void add(int x,int y){v[++ed]=y;nxt[ed]=g[x];g[x]=ed;}
 
void dfs(int x){
 pos++;
 for(int i=g[x];i;i=nxt[i])if(col[v[i]])vis[col[v[i]]]=pos;
 for(int i=1;;i++)if(vis[i]<pos){
   col[x]=i;
   break;
  }
 for(int i=g[x];i;i=nxt[i])if(!col[v[i]])dfs(v[i]);
}
 
void solve(){
 scanf("%d%d%d",&n,&m,&K);
 for(ed=0,i=1;i<=n;i++)g[i]=col[i]=0;
 while(m--)scanf("%d%d",&x,&y),add(x,y),add(y,x);
 ?for(i=1;i<=n;i++)if(!col[i])dfs(i);
 ?bool flag=0;
 ?for(i=1;i<=n;i++)if(col[i]>K){flag=1;break;}
 ?if(!flag){
   ?printf("coloring");
   ?for(i=1;i<=n;i++)printf(" %d",col[i]);
   ?return;
  }
 ?for(i=1;i<=n;i++)if(col[i]==K+1){x=i;break;}
 ?printf("path");
 ?for(i=1;i<=K+1;i++){
   ?printf(" %d",x);
   ?for(j=g[x];j;j=nxt[j])if(col[v[j]]==col[x]-1){
     ?x=v[j];
     ?break;
    }
  }
}
 
int main(){
 ?freopen("pathorcoloring.in","r",stdin);
 ?freopen("pathorcoloring.out","w",stdout);
 ?scanf("%d",&Case);
 ?while(Case--){
   ?solve();
   ?puts("");
  }
}
