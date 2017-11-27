#include<bits/stdc++.h>
using namespace std;
char s[110];
int cnt[110];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	for(int i=0;s[i];i++){
		cnt[s[i]-'a']++;
	}
	int maxm=0;
	for(int i=0;i<26;i++){
		maxm=max(maxm,cnt[i]);
	}
	if(maxm>k)puts("NO");
	else puts("YES");
}


