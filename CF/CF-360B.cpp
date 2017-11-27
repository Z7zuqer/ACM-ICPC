#include<bits/stdc++.h>
using namespace std;
char s[100100];
int main(){
	scanf("%s",s);
	for(int i=0;s[i];i++)printf("%c",s[i]);
	int len=strlen(s);
	for(int i=len-1;i>=0;i--)printf("%c",s[i]);
	cout<<endl;
}


