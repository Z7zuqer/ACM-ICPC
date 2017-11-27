#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1000100;
int len,NEXT[maxn];
char s[maxn],p[maxn];
void preNEXT(){
	int k=0;
	NEXT[0]=0;
	for(int i=1,k=0;s[i];i++){
		while(k>0&&s[k]!=s[i])k=NEXT[k-1];
		if(s[k]==s[i])k++;
		NEXT[i]=k;
	}
}
int main(){
	while(scanf("%s",s)!=EOF){
		if(s[0]=='.')break;
		preNEXT();
		len=strlen(s);
		int mx=NEXT[len-1];
		//if(len%(len-mx)==0)
			printf("%d\n",mx);
		//else printf("1\n");
	}
} 
