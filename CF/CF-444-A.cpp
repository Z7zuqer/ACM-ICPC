#include<bits/stdc++.h>
using namespace std;
char s[1000]; 
int main(){
	scanf("%s",s);
	int cnt=0,res=0,len=strlen(s);
	if(s[0]=='0'&&len==1)return 0*printf("yes");
	for(int i=len-1;i>=0;i--){
		if(s[i]=='0')res++;
		else cnt++;
		if(res>=6)break;
	}
	if(res>=6&&cnt<=2)puts("yes");
	else puts("no");
}


