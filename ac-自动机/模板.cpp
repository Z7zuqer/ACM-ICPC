struct AC_AUTO{
	const static int Alphasize=26;
	const static int Triesize=26*(1e5+50);
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
		return c-'a';
	}
	void insert(char ss[]){
		int now=root;
		for(int i=0;ss[i];i++){
			int idx=getidx(ss[i]);
			if(next[now][idx]==-1)next[now][idx]=newnode();
			now=next[now][idx];
		}
		end[now]++;
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
	int query(char s[]){
		int res=0,now=root;
		for(int i=0;s[i];i++){
			int idx=getidx(s[i]);
			int tmp=now=next[now][idx];
			while(tmp){
				res+=end[tmp];
				end[tmp]=0;
				tmp=fail[tmp];
			}
		}
		return res;
	}
	void print(){
		for(int i=0;i<tot;i++){
			printf("id = %3d,fail = %3d,end = %3d,chi = [",i,fail[i],end[i]);
			for(int j=0;j<Alphasize;j++)printf("%3d",next[i][j]);
			printf("]\n");
		}
	}
}; 


