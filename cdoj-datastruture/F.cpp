#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+7;
int tr[maxn*15+107][3],cnt;
void insert(int k){
	int x=0;
	for(int i=31;i>=0;i--){
		int alp=(k>>i)&1;
		if(!tr[x][alp])tr[x][alp]=++cnt;
		x=tr[x][alp];
	}
}
int find(int k){
	int x=0,r=0;
	for(int i=31;i>=0;i--){
		int alp=(k>>i)&1;alp^=1;
		r<<=1;
		if(tr[x][alp])x=tr[x][alp],r|=1;
		else x=tr[x][alp^1];
	}
	return r;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		insert(x);
	}
	int m;
	scanf("%d",&m);
	while(m--){
		int x;
		scanf("%d",&x);
		printf("%d\n",find(x));
	}
}


