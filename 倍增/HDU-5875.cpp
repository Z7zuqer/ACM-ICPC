#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
int n,next[maxn][30],A[maxn];
int sta[maxn];
void init_bz(){
	sta[sta[0]=1]=n;
	for(int i=0;(1<<i)<=n;i++)next[n][i]=n+1;
	for(int i=n-1;i;i--){
		while(sta[0]&&A[i]<A[sta[sta[0]]])sta[0]--;
		if(!sta[0])next[i][0]=n+1;
		else next[i][0]=sta[sta[0]];
		sta[++sta[0]]=i;
	}
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i<n;i++)
			if(next[i][j-1]!=-1)
				next[i][j]=next[next[i][j-1]][j-1];
}
int query(int l,int r){
	if(l==r)return A[l];
	int k=A[l];
	for(int i=(int)log2(n);i>=0;i--)if(next[l][i]<=r&&next[l][i]!=-1)l=next[l][i];
	if(k==0)return k;
	k%=A[l];
	while(1){
		int flg=0;
		for(int i=log2(n);i>=0;i--)
			if(next[l][i]!=-1&&next[l][i]<=r){
				l=next[l][i];
				flg=1;
			}
		if(!k)return k;
		if(!flg)return k;	
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(next,-1,sizeof next);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		init_bz();
		int q;
		scanf("%d",&q);
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%d\n",query(l,r));
		}
	}
}


