#include<bits/stdc++.h>
using namespace std;
int k;
char s[110];
int main(){
	scanf("%s%d",s,&k);
	int len=strlen(s);
	if(len<k)cout<<len-1<<endl;
	else {
		int ans=0,cnt=0;
		for(int i=len-1;i>=0;i--){
			if(s[i]!='0'){
				ans++;
			}
			else cnt++;
			if(cnt>=k)break;
		}
		cout<<ans<<endl;
	}
}


