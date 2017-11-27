#include<bits/stdc++.h>
using namespace std;
char s[1010];
int cnt[30];
int main(){
	int k;
	scanf("%s%d",s,&k);
	int len=strlen(s);
	if(k>len)return 0*printf("impossible");
	int res=0;
	for(int i=0;s[i];i++)
		if(cnt[s[i]-'a']==0){
			cnt[s[i]-'a']++;
			res++;
		}
	if(res>=k)puts("0");
	else printf("%d\n",k-res);
}


