#include<bits/stdc++.h>
using namespace std;
int vis[50010],A[50010],B[50010];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof vis);
		int n,m,q;
		bitset<50002>b,c,d,ans;
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)scanf("%d",&A[i]),b.set(A[i]);
		for(int i=1;i<=m;i++){
			scanf("%d",&B[i]);
			if(B[i]==1){
				ans.flip();
				continue;
			}
			d=b;
			while(d.count()>0){
				c|=d;
				d>>=B[i];
			}
			bitset<50002>e((1<<B[i])-1);
			c&=e;
			ans^=c;
		}
		while(q--){
			int k;
			scanf("%d",&k);
			printf("%d\n",ans.test(k));
		}
		
	}
}


