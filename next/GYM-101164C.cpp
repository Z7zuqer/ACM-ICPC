#include<bits/stdc++.h>
using namespace std;
const int maxn=1310000;
int NEXT[maxn],len;
char s[maxn];
int tr[maxn],vis[maxn];
void add(int x,int v){
	while(x<maxn){
		tr[x]+=v;
		x+=x&-x; 
	}
}
int getans(int x){
	int ans=0;
	while(x){
		ans+=tr[x];
		x-=x&-x;
	}
	return ans;
}
void preNEXT(){
	NEXT[0]=0;
	for(int i=1,k=0;s[i];i++){
		while(k>0&&s[i]!=s[k])k=NEXT[k-1];
		if(s[i]==s[k])k++;
		NEXT[i]=k;
	}
}
void add_c(char c){
	int k=NEXT[len-1];
	while(k>0&&c!=s[k])k=NEXT[k-1];
	if(s[k]==c)k++;
	NEXT[len]=k;s[len]=c;len++;
}
int main(){
	int e;
	scanf("%d%d",&len,&e);
	scanf("%s",s);
	preNEXT();
	while(e--){
		int k;
		char c[2];
		scanf("%d",&k);
		if(k==1){
			scanf("%s",c);
			add_c(c[0]);
		}
		if(k==2)
			if(!vis[len])add(len,1),vis[len]=1;
		if(k==3){
			int ans=getans(NEXT[len-1]);
			ans+=vis[len];
			printf("%d\n",ans);
		}
	}
}


