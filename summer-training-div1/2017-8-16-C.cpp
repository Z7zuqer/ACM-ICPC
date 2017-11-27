#include<bits/stdc++.h>
using namespace std;
struct {
	int a[7];
	void scan(){
		for(int i=1;i<=6;i++)scanf("%d",&a[i]);
	}
	void rota(){
		int t=a[1];
		for(int i=1;i<=5;i++)a[i]=a[i+1];
		a[6]=t;
	}
}a[10],t[10];
int pos[8]={0,0,4,5,6,1,2,3};
int px[8]={0,0,3,4,5,6,1,2};
int py[8]={0,0,6,1,2,3,4,5};
int b[10],vis[10];
int dfs(int k){
	if(k==8){
		for(int i=1;i<=7;i++)printf("%d ",b[i]-1);
		puts("");
		return 1;
	}
	for(int i=1;i<=7;i++){
		if(!vis[i]){
			t[k]=a[i];
			b[k]=i;
			if(k==1){
				while(t[k].a[1]!=1)t[k].rota();
			}
			else {
				while(t[k].a[pos[k]]!=t[1].a[k-1])t[k].rota();
				if(k>2&&t[k].a[py[k-1]]!=t[k-1].a[px[k-1]])continue;			
				if(k==7&&t[k].a[px[k]]!=t[2].a[py[k]])continue;
			}
			vis[i]=1;
			if(dfs(k+1))return 1;
			vis[i]=0;
		}
	}
	return 0;
}
int main(){
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=7;i++)a[i].scan();
		printf("Case %d: ",cas++);
		memset(vis,0,sizeof vis);
		if(!dfs(1))printf("No solution\n");
	}
}
