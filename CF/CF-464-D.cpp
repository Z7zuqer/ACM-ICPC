#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int fa[35],rk[35];
char s[maxn],t[maxn];
int find(int x){
	return fa[x]==x?x:find(fa[x]);
}
void uni(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		rk[fx]+=rk[fy];
		fa[fy]=fx;
	}
}
int pre[30],vis[30];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=26;i++){
		fa[i]=i;
		rk[i]=1;
	}
	memset(pre,-1,sizeof pre);
	for(int i=1;i<=n;i++){
		if(s[i]!=t[i]){
			uni(s[i]-'a'+1,t[i]-'a'+1);
		}
	}
	int ans=0;
	for(int i=1;i<=26;i++){
		if(!vis[find(i)]){
			ans+=rk[find(i)]-1;
			vis[find(i)]=1;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=26;i++){
		if(fa[i]!=i)
			printf("%c %c\n",fa[i]+'a'-1,i+'a'-1);
	}
	//printf("%c %c\n",pre[find(i)]-1+'a','a'+i-1);
}


