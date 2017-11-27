#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,wh;
}r[1000100];
int cmp(node m,node n){
	return m.x>n.x;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i].x);
		r[i].wh=i;
	} 
	sort(r+1,r+1+n,cmp);
	for(int i=1;i<=n;i++){
		
	}
}


