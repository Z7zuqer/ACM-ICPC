#include<bits/stdc++.h>
using namespace std;
char s[1010];
int n,p; 
int check(){
	for(int i=0;i<n;i++){
		if(s[i]<'a'||s[i]>'z')return 0;
		else if(i<n-1&&s[i]==s[i+1])return 0;
		else if(i>=1&&i<n-1&&s[i-1]==s[i+1])return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&p);
	scanf("%s",s);
	//strcpy(pa,s);
	while(1){
		int now=n-1;
		while(s[now]<'a'+p-1){
			s[now]++;
			if(check())return 0*printf("%s\n",s);
		}
		while(s[now]>='a'+p-1)now--;
		if(now==-1)return 0*printf("NO\n");
		s[now]++;
		for(int j=now+1;j<n;j++)s[j]='a'-1;
	}
}


