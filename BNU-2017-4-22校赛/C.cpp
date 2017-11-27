#include<bits/stdc++.h>
using namespace std;
char ss[5][11]={"zero","two","four","six","nine"};
char s[100100];
vector<char>v;
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(s,0,sizeof s);
		scanf("%s",s);
		v.clear();
		for(int i=0;s[i];i++){
			if(s[i]=='2'||s[i]=='0'||s[i]=='4'||s[i]=='6'||s[i]=='9')v.push_back(s[i]);
			else if(s[i]=='z'&&s[i+1]=='e'&&s[i+2]=='r'&&s[i+3]=='o')v.push_back('0');//,v.push_back('e'),v.push_back('r'),v.push_back('o');
			else if(s[i]=='f'&&s[i+1]=='o'&&s[i+2]=='u'&&s[i+3]=='r')v.push_back('4');//,v.push_back(''),v.push_back('r'),v.push_back('o'),;
			else if(s[i]=='n'&&s[i+1]=='i'&&s[i+2]=='n'&&s[i+3]=='e')v.push_back('9');
			else if(s[i]=='s'&&s[i+1]=='i'&&s[i+2]=='x')v.push_back('6');
			else if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')v.push_back('2');
		}
		for(int i=0;i<v.size();i++)printf("%c",v[i]);cout<<endl;
	}
}
