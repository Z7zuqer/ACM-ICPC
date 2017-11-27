#include<bits/stdc++.h>
using namespace std;
char s[500];
int main(){
	int ans=0;
	scanf("%s",s);
	for(int i=0;s[i];i+=3){
		if(s[i]!='P')ans++;
		if(s[i+1]!='E')ans++;
		if(s[i+2]!='R')ans++;
	}
	cout<<ans<<endl;
}


