#include<bits/stdc++.h>
using namespace std;
int vis[1010],n;
char str[1010][51];
struct AC_AUTO{
	const static int Alphasize=27;
	const static int Triesize=2000010;
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
		if(c>='A'&&c<='Z')return c-'A';
		return 26;
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
	void query(char s[]){
		int res=0,now=root;
		memset(vis,0,sizeof vis);
		for(int i=0;s[i];i++){
			int idx=getidx(s[i]);
			if(idx==-1)continue;
			int tmp=now=next[now][idx];
			while(tmp){
				res+=end[tmp];
				vis[end[tmp]]++;
				tmp=fail[tmp];
			}
		}
		for(int i=1;i<=n;i++)
			if(vis[i])
				printf("%s: %d\n",str[i],vis[i]);
		//return res;
	}
	void print(){
		for(int i=0;i<tot;i++){
			printf("id = %3d,fail = %3d,end = %3d,chi = [",i,fail[i],end[i]);
			for(int j=0;j<Alphasize;j++)printf("%3d",next[i][j]);
			printf("]\n");
		}
	}
}ac; 
char p[2000010];//,pat[2000010];
int main(){
	while(scanf("%d",&n)!=EOF){
		ac.init();
		for(int i=1;i<=n;i++){
			scanf("%s",str[i]);
			ac.insert(str[i],i);
		}
		ac.build();
		scanf("%s",p);
		//int len=0;
		//for(int i=0;p[i];i++)if(p[i]>='A'&&p[i]<='Z')pat[len++]=p[i];
		//pat[len]='\0';
		ac.query(p);
	}
}


