#include<bits/stdc++.h>
using namespace std;
char mp[30][30];
int sta[30][30][30][30];
int dfs(int sx,int sy,int ex,int ey){
    if(sta[sx][sy][ex][ey]!=-1) return sta[sx][sy][ex][ey];
    set<int>s;
  	for(int i=sx;i<ex;i++){
         for(int j=sy;j<ey;j++){
             if(mp[i][j]!='X'){
      	   	    int k=0;
      	        k^=dfs(sx,sy,i,j);
      	        k^=dfs(i+1,j+1,ex,ey);
      	        k^=dfs(sx,j+1,i,ey);
      	        k^=dfs(i+1,sy,ex,j);
                s.insert(k);
                //cout<<k<<endl;
             } 
         } 
    }
    int tmp=0;
    while(s.count(tmp))tmp++;
    //cout<<tmp<<endl;
    return sta[sx][sy][ex][ey]=tmp;
}
int main(){
	int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",mp[i]);
    memset(sta,-1,sizeof(sta));
    int flg=dfs(0,0,n,m);
    if(flg>0)puts("First");else puts("Second");
}
