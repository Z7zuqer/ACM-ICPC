#include<bits/stdc++.h>
using namespace std;
int vis[1010],n;
struct AC_AUTO{
	const static int Alphasize=128;
	const static int Triesize=128*(1e3);
	int tot,root,fail[Triesize],end[Triesize],next[Triesize][Alphasize];
	int newnode(){
		memset(next[tot],-1,sizeof next[tot]);
		end[tot]=0;
		return tot++;
	}
	void init(){
		tot=0;
		root=newnode();
	}
	int getidx(char c){
		return (int)c;
	}
	void insert(char ss[],int x){
		int now=root;
		for(int i=0;ss[i];i++){
			int idx=getidx(ss[i]);
			if(next[now][idx]==-1)next[now][idx]=newnode();
			now=next[now][idx];
		}
		end[now]=x;
	}
	void build(){
		queue<int>q;
		fail[root]=root;
		for(int i=0;i<Alphasize;i++)
			if(next[root][i]==-1)next[root][i]=root;
			else fail[next[root][i]]=root,q.push(next[root][i]);
		while(q.size()){
			int now=q.front();q.pop();
			for(int i=0;i<Alphasize;i++)
				if(next[now][i]==-1)next[now][i]=next[fail[now]][i];
				else fail[next[now][i]]=next[fail[now]][i],q.push(next[now][i]);

		}
	}
	int query(char s[],int idx){
		int res=0,now=root,flg=0;
		memset(vis,0,sizeof vis);
		for(int i=0;s[i];i++){
			int idx=getidx(s[i]);
			int tmp=now=next[now][idx];
			while(tmp){
				if(end[tmp])vis[end[tmp]]=1,flg=1;
				tmp=fail[tmp];
			}
		}
		if(!flg)return 0;
		printf("web %d:",idx);
		for(int i=1;i<=n;i++)if(vis[i])printf(" %d",i);
		printf("\n");
		return 1;
	}
	void print(){
		for(int i=0;i<tot;i++){
			printf("id = %3d,fail = %3d,end = %3d,chi = [",i,fail[i],end[i]);
			for(int j=0;j<Alphasize;j++)printf("%3d",next[i][j]);
			printf("]\n");
		}
	}
}ac; 
char s[220],p[10010];
int main(){
	while(scanf("%d",&n)!=EOF){
		ac.init();
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			ac.insert(s,i);
		}
		ac.build();
		int m;
		scanf("%d",&m);
		int total=0,res=0;
		for(int i=1;i<=m;i++){
			scanf("%s",p);
			total+=ac.query(p,i);
		}
		printf("total: %d\n",total);
	}
}


