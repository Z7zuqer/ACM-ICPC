#include<bits/stdc++.h>
using namespace std;
int last[200200];
struct node{
	int x,v;
}r[200200];
int cmp(node m,node n){
	return m.x>n.x;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k); 
	//for(int i=1;i<=n;i++)last[i]=i;
	for(int i=1;i<=k;i++){
		int a;
		scanf("%d",&a);
		last[a]=i;
	}
	int tot=0;
	for(int i=1;i<=n;i++)
		if(last[i])
			r[++tot]={last[i],i};
	sort(r+1,r+1+tot,cmp);
	for(int i=1;i<=tot;i++)
		printf("%d\n",r[i].v);
	for(int i=1;i<=n;i++) 
		if(!last[i])
			printf("%d\n",i);
}




