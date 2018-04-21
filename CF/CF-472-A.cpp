#include<bits/stdc++.h>
using namespace std;
int n;
char s[110]; 
int main(){
	scanf("%d%s",&n,s);
	int ans=0,len=strlen(s),flg=0;
	for(int i=0;s[i];i++){
		int cnt=0;
		if(s[i]!='?'){
			if(i>0&&s[i]==s[i-1])return 0*printf("No\n");
			continue;
		}
		for(int j=i;s[j];j++)
			if(s[j]=='?')cnt++;
			else break;
		if(cnt>=2)flg=1;
		if(i==len-1)flg=1;
		if(i==0)flg=1;
		if(s[i-1]==s[i+1]){
			if(ans==0)ans=2;
			else ans*=2;
		}
	}
	if(ans>=2||flg)return 0*printf("Yes\n");
	puts("No");
}


