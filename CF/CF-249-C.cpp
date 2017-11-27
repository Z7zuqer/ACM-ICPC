#include<bits/stdc++.h>
using namespace std;
int A[1010];
int X[1010],Y[1010];
char mp[3010][3010];
void work(int idx_pre,int idx_now){
	int prex=X[idx_pre],prey=Y[idx_pre];
	int nowx=X[idx_now],nowy=Y[idx_now];
	if(nowy<prey)
		for(int i=prex;i<nowx;i++)mp[--prey][i]='\\';//,cout<<prey<<" "<<i<<endl;
	else 
		for(int i=prex;i<nowx;i++)mp[prey++][i]='/';
}
int main(){
	int n;
	scanf("%d",&n);
	memset(mp,-1,sizeof mp);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	int maxY=1000,minY=1000;
	Y[0]=1000;
	for(int i=1;i<=n;i++){
		X[i]=X[i-1]+A[i];
		if(i&1)Y[i]=Y[i-1]+A[i];
		else Y[i]=Y[i-1]-A[i];
		maxY=max(maxY,Y[i]);
		minY=min(minY,Y[i]); 
	}
	//for(int i=1;i<=n;i++)printf("%d %d\n",X[i],Y[i]);
	for(int i=1;i<=n;i++)work(i-1,i);
	for(int i=maxY-1;i>=minY;i--,puts(""))
		for(int j=0;j<X[n];j++)
			if(mp[i][j]==-1)printf(" ");
			else printf("%c",mp[i][j]);
}


