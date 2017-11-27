#include<bits/stdc++.h>
using namespace std;
int ans[1010][1010];
int n,k,d;
void work(int sta,int wh){
	int len=0;
	while(sta){
		if(sta%k==0)ans[wh][len+1]=k;
		else ans[wh][len+1]=sta%k;
		sta/=k;
		len++;
		if(len>d)break;
	}
	for(int i=len+1;i<=d;i++)ans[wh][i]=k;
}
int main(){
	scanf("%d%d%d",&n,&k,&d);
	int res=1,flg=0;
	for(int i=1;i<=d;i++){
		if(1LL*res*k>=n){
			flg=1;
			break;
		}
		res*=k;
	}
	if(!flg)return 0*printf("-1\n");
	int now=0;
	for(int i=1;i<=n;i++)work(i,i);
	for(int j=1;j<=d;j++){
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
}


