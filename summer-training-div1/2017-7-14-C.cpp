#include<bits/stdc++.h>
using namespace std;
char mp[27][27];
int n,m,cnt[27],num[(1<<25)];
int ans=1e9;
int getnum(int k){
	int ans=0;
	while(k){
		ans+=k&1;
		k>>=1;
	}
	return ans;
}
void dfs(int x,int used,int mask){
	if(x>n){
		int k;
		if(mask&&!num[mask])k=getnum(mask);
		else k=num[mask];
		num[mask]=k;
		ans=min(ans,max(used,k));
		return ;		
	}
	dfs(x+1,used+1,mask);
	dfs(x+1,used,mask|cnt[x]);
}
template <class T>
inline void scan_d(T &ret) 
{
    char c; 
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    { 
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
void Out(int a) 
{   //  Êä³öÍâ¹Ò  
    if (a < 0) 
    {
        putchar('-');
        a = -a;
    }  
    if (a >= 10)
    {
       Out(a / 10);  
    }
    putchar(a % 10 + '0');  
}  

int main(){
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	//scanf("%d%d",&n,&m);
	scan_d(n);scan_d(m);
	for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			if(mp[i][j]=='*')
				cnt[i]|=(1<<(j-1));
	}
	dfs(0,0,0);
	Out(ans);
	//printf("%d\n",ans);
}
