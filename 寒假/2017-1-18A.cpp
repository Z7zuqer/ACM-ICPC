#include<bits/stdc++.h>
using namespace std;
char s[50];
int main(){
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cnt++;
		scanf("%s",s);
		for(int j=0;s[j];j++)
			if(s[j]=='+'){
				cnt++;
				break;
			}
	}
	cnt+=2;
	if(cnt==13)cnt++;
	cout<<cnt*100<<endl;
}


