#include<bits/stdc++.h>
using namespace std;
int num[11],op[11],;
void dfs(int now,int )
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			if(i==1)scanf("%d",num[i]);
			else {
				char s[2];
				scanf("%s",s);
				if(s[0]=='+')op[i-1]=1;
				if(s[0]=='-')op[i-1]=2;
				if(s[0]=='*')op[i-1]=3;
				scanf("%d",&num[i]);
			}
		}
		printf("%)
	}
}
