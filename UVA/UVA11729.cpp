#include<bits/stdc++.h>
using namespace std;
struct node{
	int b,j;
}r[1010];
bool cmp(node m,node n){
	if(m.j==n.j)return m.b<n.b;
	return m.j>n.j;
}
int main(){
	int n,cas=1;
	while(~scanf("%d",&n)){
		if(!n)break;
		for(int i=1;i<=n;i++)scanf("%d%d",&r[i].b,&r[i].j);
		sort(r+1,r+1+n,cmp);
		int t1=0,t2=0;
		for(int i=1;i<=n;i++){
			t1+=r[i].b;
			t2=max(t2,t1+r[i].j);
		}
		printf("Case %d: ",cas++);
		cout<<max(t1,t2)<<endl;
	}
}
