#include<bits/stdc++.h>
using namespace std;
char s[100010];
int main(){
	scanf("%s",s);
	int len=strlen(s);
	int ans=(s[0]==s[len-1])^(len%2);
	if(!ans)cout<<"Second"<<endl;
	else cout<<"First"<<endl;
}


