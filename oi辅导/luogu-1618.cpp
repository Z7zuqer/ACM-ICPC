#include<bits/stdc++.h>
using namespace std;
int r[5]={1,10,100},A,B,C,vis[14],flg;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
void dfs(int now,int a,int b,int c){
	if(now>9){
		int div=gcd(a,gcd(b,c));
		a/=div;b/=div;c/=div;
		if(a==A&&b==B&&c==C)printf("%d %d %d\n",a*div,b*div,c*div),flg=1;
		return ;
	}
	for(int i=1;i<=9;i++)
		if(!vis[i]){
			vis[i]=1;
			if(now<=3)dfs(now+1,a+i*r[3-now],b,c);
			else if(now<=6)dfs(now+1,a,b+i*r[6-now],c);
			else dfs(now+1,a,b,c+i*r[9-now]);
			vis[i]=0;
		}
}
int main(){
	scanf("%d%d%d",&A,&B,&C);
	int div=gcd(gcd(A,B),C);
	A/=div;B/=div;C/=div;
	dfs(1,0,0,0);
	if(!flg)puts("No!!!");
}
