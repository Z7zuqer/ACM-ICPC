#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	char s[2020];
	scanf("%s",s);
	char ans[2020];
	if(n%2==1){
		int cnt=n-1;
		for(int i=0;i<n/2;i++){
			ans[i]=s[cnt-1];
			cnt-=2;
		}
		cnt=3;
		for(int i=n/2+1;i<n;i++){
			ans[i]=s[cnt-1];
			cnt+=2;
		}
		for(int i=0;i<n;i++){
			if(i==n/2)cout<<s[0];
			else cout<<ans[i];
		}
	}
	else {
		int cnt=n/2,e=0;
		for(int i=0;i<n;i+=2){
			ans[cnt-1-e]=s[i];
			ans[cnt+e]=s[i+1];
			e++;
		}
		for(int i=0;i<n;i++)cout<<ans[i];
	}
}
