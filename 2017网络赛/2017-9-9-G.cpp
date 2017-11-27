#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
struct {
	int cnt;
	int lsta,rsta;
}tr[maxn<<2];
char s[maxn],pa[maxn];
void build(int t,int l,int r){
	tr[t].cnt=tr[t].lsta=tr[t].rsta=0;
	if(l==r){
		for(int i=1;pa[i];i++)if(pa[i]==s[l]){
			tr[t].lsta=tr[t].rsta=1<<(i-1);
			break;
		}
		return ;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m;
		scanf("%d",&m);
		scanf("%s%s",s+1,pa+1);
		int n=strlen(s+1);
		build(1,1,n);
	}
}


