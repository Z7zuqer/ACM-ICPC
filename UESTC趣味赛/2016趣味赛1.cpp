#include<bits/stdc++.h>
using namespace std;
char s[100010];
int len;
int main(){
	scanf("%d%s",&len,s);
	int ans=0;
	int now=1;
	int cnt=0;
	for(int i=0;s[i];i++)if(s[i]=='1')cnt++;
	int r=abs(len/2-cnt);
	for(int i=0;s[i];i++){
		if(now&&s[i]=='0');
		else if(!now&&s[i]=='1');
		else ans++;
		now=!now;
	}
	int k=0;
	now=1;
	for(int i=0;s[i];i++){
		if(now&&s[i]=='1');
		else if(!now&&s[i]=='0');
		else k++;
		now=!now;
	}
	ans=min(ans,k);
	cout<<ans<<endl;
}
