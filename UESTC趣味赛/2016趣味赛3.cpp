#include<bits/stdc++.h>
using namespace std;
char s[100010];
int main(){
	int n;
	scanf("%d%s",&n,s);
	int re1=0,re2=0,ans=100010;
	int now=1;
	for(int i=0;i<n;i++){
		if(now&&s[i]!='1')re1++;
		else if(!now&&s[i]!='0')re2++;
		now=!now;
	}
	ans=min(ans,max(re1,re2));
	re1=re2=0;
	now=1;
	for(int i=0;i<n;i++){
		if(now&&s[i]!='0')re1++;
		else if(!now&&s[i]!='1')re2++;
		now=!now;
	}
	ans=min(ans,max(re1,re2));
	cout<<ans<<endl;
}
