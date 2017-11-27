#include<bits/stdc++.h>
using namespace std;
int main(){
	char s[111];
	scanf("%s",s);
	int n=strlen(s),cnt=0; 
	if(n==1){
		cout<<"YES"<<endl;
		return 0;
	}
	for(int i=0;s[i];i++){
		if(n-i-1<=i)break;
		if(s[i]!=s[n-i-1])
			cnt++;
	}
	if((n&1)&&cnt==0)cout<<"YES"<<endl;
	else if(cnt!=1)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}


