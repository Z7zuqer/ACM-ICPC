#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int c[maxn][maxn],n=maxn;
void add(int x,int y,int v){
	for(int i=x;i<=n;i+=i&-i)
		for(int j=y;j<=n;j+=j&-j)
			c[i][j]+=v;
}
int getans(int x,int y){
	int ans=0;
	for(int i=x;i;i-=i&-i)
		for(int j=y;j;j-=j&-j)
			ans+=c[i][j];
	return ans;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(c,0,sizeof c);
		int nn;
		scanf("%d",&nn);
		while(nn--){
			char s[2];
			scanf("%s",s);
			if(s[0]=='C'){
				int x1,y1,x2,y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				add(x1,y1,1);
				add(x2+1,y1,1);
				add(x1,y2+1,1);
				add(x2+1,y2+1,1);
			}
			if(s[0]=='Q'){
				int x,y;
				scanf("%d%d",&x,&y);
				if(getans(x,y)&1)puts("1");
				else puts("0");
			} 
		} 
	}
}


