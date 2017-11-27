#include<bits/stdc++.h>
using namespace std;
char s[1200];
int main(){
	int k=0;
	cin>>k;
	getchar();
	//string s;
	gets(s);
	int ans=0,maxm=0;//,siz=s.size();
	for(int i=0;i<k;i++){
		if(s[i]>='A'&&s[i]<='Z')ans++;
		if(s[i]==' '){
			
			maxm=max(maxm,ans);ans=0;
		}
	}
	maxm=max(maxm,ans);
	cout<<maxm<<endl;
}


