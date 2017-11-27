#include<bits/stdc++.h>
using namespace std;
int A[13]={6,2,5,5,4,5,6,3,7,6},r[5],ans;
int cal(int x){
	if(x==0)return A[0];
	int res=0;
	while(x){
		res+=A[x%10];
		x/=10;
	}
	return res;
}
void dfs(int now,int sum){
	if(now>=3){
		int rem=r[1]+r[2];
		if(cal(rem)==sum)ans++;
		return ;
	}
	for(int i=0;i<=3000;i++){
		if(cal(i)<=sum){
			r[now]=i;
			dfs(now+1,sum-cal(i));
		} 
	}
}
int main(){
	int n;
	scanf("%d",&n);
	n-=4;if(n<0)return 0*printf("0\n");
	dfs(1,n);
	printf("%d\n",ans);
}


