#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
int n,m;
int mp[maxn][maxn];
int top=0;
int ans1,ans2;
int h[maxn][maxn];
struct node{
	int low,h;
}s[maxn];
void push(int i,int h){
	int now=i;
	while(top&&s[top].h>h){
		ans1=max(ans1,min(i-s[top].low,s[top].h)*min(i-s[top].low,s[top].h));
		ans2=max(ans2,(i-s[top].low)*s[top].h);
		now=s[top--].low;
	}
	s[++top]={now,h};
}
void work(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			h[i][j]=mp[i][j]?h[i][j-1]+1:0;
	for(int j=1;j<=m;j++){
		top=0;
		for(int i=1;i<=n;i++)
			push(i,h[i][j]);
		push(n+1,-1);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&mp[i][j]);
			if((i+j)%2==1)mp[i][j]=!mp[i][j];
		}
	work();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			mp[i][j]=!mp[i][j];
	work();
	printf("%d\n%d\n",ans1,ans2);
}
