#include<bits/stdc++.h>
using namespace std;
int num[100];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			num[i+j]++;
	int k=1;
	for(int i=1;i<=40;i++)if(num[i]>num[k])k=i;
	for(int i=1;i<=40;i++)
		if(num[i]==num[k])
			printf("%d\n",i);
}


