#include<bits/stdc++.h>
using namespace std;
struct node{
	int tot,yw,sx,yy,idx;
}r[600];
int cmp(node m,node n){
	if(m.tot!=n.tot)return m.tot>n.tot;
	if(m.yw!=n.yw)return m.yw>n.yw;
	return m.idx<n.idx;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&r[i].yw,&r[i].sx,&r[i].yy);
		r[i].tot=r[i].yw+r[i].sx+r[i].yy;
		r[i].idx=i;
	}
	sort(r+1,r+1+n,cmp);
	for(int i=1;i<=5;i++)
		printf("%d %d\n",r[i].idx,r[i].tot);
}


