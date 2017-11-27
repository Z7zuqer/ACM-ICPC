#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
int mp[maxn][maxn];
int l[maxn][maxn],r[maxn][maxn];
int h[maxn][maxn];
struct {
	int h,low;
}s[maxn];
int ans1,ans2,n,m;
void work(){
	memset(h,0,sizeof(h));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!mp[i][j])h[i][j]=h[i-1][j]+1;
	for(int i=1;i<=n;i++){
		int top=0;
		s[++top]={-1,0};
		for(int j=1;j<=m;j++){
			while(h[i][j]<=s[top].h)top--;
			l[i][j]=j-s[top].low-1;
			s[++top]={h[i][j],j};
		}
	}
	for(int i=1;i<=n;i++){
		int top=0;
		s[++top]={-1,m+1};
		for(int j=m;j>=1;j--){
			while(h[i][j]<=s[top].h)top--;
			r[i][j]=s[top].low-j-1;
			s[++top]={h[i][j],j};
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			ans2=max(ans2,min((l[i][j]+r[i][j]+1),h[i][j])*min((l[i][j]+r[i][j]+1),h[i][j]));
			ans1=max(ans1,(l[i][j]+r[i][j]+1)*h[i][j]);
		}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&mp[i][j]);
			if((i+j)%2)mp[i][j]=!mp[i][j];
		}
	work();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			mp[i][j]=!mp[i][j];
	work();
	cout<<ans2<<endl<<ans1<<endl;;
}
