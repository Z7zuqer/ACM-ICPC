#include<bits/stdc++.h>
using namespace std;
char s[101000],p[10100]; 
int len_p,pos=-1,vis[28];
int check(char a,char b){
	if(a==b)return 1;
	if(a=='?'&&b>='a'&&b<='z'&&vis[b-'a'])return 1;
	if(b=='?'&&a>='a'&&a<='z'&&vis[a-'a'])return 1;
	return 0;
}
int work(){
	if(pos==-1){
		int len_s=strlen(s),flg=0;
		if(len_s!=len_p)return 0;
		for(int i=0;s[i];i++)if(!check(s[i],p[i]))return 0;
		return 1;
	} 
	int len_s=strlen(s);
	if(len_s+1<len_p)return 0;
	int sta=0,end=len_s-1;
	for(int i=sta;i<pos;i++,sta++)if(!check(s[i],p[i]))return 0;
	for(int i=len_p-1;i>pos;i--,end--)if(!check(s[end],p[i]))return 0;
	for(int i=sta;i<=end;i++)if(s[i]=='?'||vis[s[i]-'a'])return 0;
	return 1;
}
int main(){
	scanf("%s",s);
	for(int i=0;s[i];i++)vis[s[i]-'a']=1;
	scanf("%s",p);
	len_p=strlen(p);
	for(int i=0;i<len_p;i++)if(p[i]=='*')pos=i;
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%s",s);
		if(work())puts("YES");
		else puts("NO");
	} 
}

