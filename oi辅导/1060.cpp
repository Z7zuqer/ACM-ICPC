#include<bits/stdc++.h>
using namespace std;
char s[10101],p[101010];
int main(){
	gets(s);getchar();
	gets(p);
	int len=strlen(s);
	for(int i=0;i<len;i++)
		if(s[i]==p[i])printf("%d ",i+1);
	
}


