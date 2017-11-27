#include<bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
const int maxn=5010;
ULL h1[maxn],h2,h37[maxn];
char s1[maxn],s2[maxn];
int trans(char c){
	if(c>='a'&&c<='z')return c-'a';
	return c-'A';
}
void print(int sta_1,int sta_2,int end_3){
	
}
int main(){
	scanf("%s%s",s1,s2);
	h1[0]=trans(s1[0]);
	ULL n=strlen(s1);
	for(int i=1;s1[i];i++)h1[i]=h1[i-1]*37+trans(s1[i]);
	h2=trans(s2[0]);
	for(int i=1;s2[i];i++)h2=h2*37+trans(s2[i]);
	h37[0]=1;
	int flg=0;
	for(int i=1;i<maxn;i++)h37[i]=h37[i-1]*37;
	for(int i=0;i<n-2;i++)
		for(int j=i+1;j<n-1;j++){
			ULL hx=h1[i],hy=h1[j]-h1[i]*h37[j-i],hz=h1[n-1]-h1[j]*h37[n-1-j];
			if(h1[n-1]==h2)flg=1;
			if(hx*h37[n-1-i]+hz*h37[j-i]+hy==h2)flg=1;
			else if(hy*h37[n+i-j]+hx*h37[n-1-j]+hz==h2)flg=1;
			else if(hy*h37[n+i-j]+hz*h37[i+1]+hx==h2)flg=1;
			else if(hz*h37[j+1]+hx*h37[j-i]+hy==h2)flg=1;
			else if(hz*h37[j+1]+hy*h37[i+1]+hx==h2)flg=1;
			if(flg){
				puts("YES");
				for(int k=0;k<=i;k++)printf("%c",s1[k]);puts("");
				for(int k=i+1;k<=j;k++)printf("%c",s1[k]);puts("");
				for(int k=j+1;k<=n-1;k++)printf("%c",s1[k]);puts("");
				return 0;
			}
		} 
	puts("NO");
}


