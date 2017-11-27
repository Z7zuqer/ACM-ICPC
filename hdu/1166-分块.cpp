#include<bits/stdc++.h>
using namespace std;
const int maxn=50010;
int magic,block[maxn],size[maxn],A[maxn];
void update(int x,int y){
	int x_pos=x/magic;
	for(int i=x;i<=x_pos*magic+size[x_pos]-1;i++)block[i]+=y;
}
void init(int k){
	block[k*magic]=A[k*magic];
	for(int i=k*magic+1;i<k*magic+size[k];i++)block[i]=block[i-1]+A[i];
}
int query(int x,int y){
	int x_pos=x/magic,y_pos=y/magic,r=0;
	if(x_pos==y_pos)return block[y]-((x%magic==0)?0:block[x-1]);
	else {
		r+=block[x_pos*magic+size[x_pos]-1]-((x%magic==0)?0:block[x-1]);
		for(int i=x_pos+1;i<y_pos;i++)r+=block[i*magic+size[i]-1];
		r+=block[y];
	}
	return r;
}
int main(){
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&A[i]);
		magic=sqrt(n);int sz=n/magic;
		for(int i=0;i<=sz;i++)size[i]=min(magic,n-i*magic);
		for(int i=0;i<=sz;i++)init(i);	
		char s[11];
		printf("Case %d:\n",cas++);
		while(~scanf("%s",s)){
			if(s[0]=='E')break;
			int x,y;
			scanf("%d%d",&x,&y);
			if(s[0]=='A')update(x-1,y);
			if(s[0]=='Q')printf("%d\n",query(x-1,y-1));
			if(s[0]=='S')update(x-1,-y);
		}
	}
}


