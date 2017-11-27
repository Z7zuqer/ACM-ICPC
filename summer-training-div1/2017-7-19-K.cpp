#include<bits/stdc++.h>
using namespace std;
char s[300100];
vector<int>ans;
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i+=3){
		int a=s[i]-'0',b=s[i+1]-'0',c=s[i+2]-'0';
		if(s[i-1]=='0'){
			if(a==0&&b==0&&c==0)ans.push_back(i);
			else if(a==0&&b==0&&c==1)ans.push_back(i+1),s[i+2]='0';
			else if(a==0&&b==1&&c==1)ans.push_back(i);
			else if(a==1&&b==1&&c==1)ans.push_back(i+1),s[i+2]='0';
		}
		else{
			if(a==0&&b==0&&c==0)ans.push_back(i+1),s[i+2]='1';
			else if(a==1&&b==0&&c==0)ans.push_back(i);
			else if(a==1&&b==1&&c==0)ans.push_back(i+1),s[i+2]='1';
			else if(a==1&&b==1&&c==1)ans.push_back(i);
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
	cout<<endl;
}
