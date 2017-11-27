#include<bits/stdc++.h>
using namespace std;
int n,m,A[110][110];
char s[1010];
void workA(){
	int tmp[110][110];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			tmp[j][n-i+1]=A[i][j];
	swap(n,m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			A[i][j]=tmp[i][j];
}
void workB(){
	int tmp[110][110];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			tmp[m-j+1][i]=A[i][j];
	swap(n,m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			A[i][j]=tmp[i][j];
}
void workC(){
	int tmp[110][110];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			tmp[i][m-j+1]=A[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			A[i][j]=tmp[i][j];
}
void workD(){
	int tmp[110][110];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			tmp[n-i+1][j]=A[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			A[i][j]=tmp[i][j];
}
void print(){
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++)
			printf("%d ",A[i][j]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&A[i][j]);
	scanf("%s",s);
	for(int i=0;s[i];i++){
		if(s[i]=='A')workA();
		else if(s[i]=='B')workB();
		else if(s[i]=='C')workC();
		else workD();
		//print();
	}
	print();
}


