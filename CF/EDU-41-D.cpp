#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct {
	LL x,y;
}A[100100];
int n;
int check(int x,int y,int z){
	LL X=(A[x].y-A[y].y)*(A[y].x-A[z].x);
	LL Y=(A[y].y-A[z].y)*(A[x].x-A[y].x);
	return X==Y;
}
vector<int>v;
int work(int a,int b){
	v.clear();
	for(int i=0;i<n;i++)
		if(i!=a&&i!=b&&!check(a,b,i))
			v.push_back(i);
	if(v.size()<=2)return 1;
	for(int i=2;i<v.size();i++)
		if(!check(v[i-2],v[i-1],v[i]))
			return 0;
	return 1;
}
int main(){
	srand((unsigned long long)new char);
	scanf("%d",&n);
	if(n<=3)return 0*printf("YES\n");
	for(int i=0;i<n;i++)scanf("%lld%lld",&A[i].x,&A[i].y);
	int a=1LL*rand()*rand()%n;
	int b=1LL*rand()*rand()%n;
	while(b==a)b=1LL*rand()*rand()%n;
	int c=1LL*rand()*rand()%n;
	while(c==b||c==a)c=1LL*rand()*rand()%n;
	if(work(a,b)||work(b,c)||work(a,c))puts("YES");
	else puts("NO");
}


