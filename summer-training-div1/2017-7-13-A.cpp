#include<bits/stdc++.h>
using namespace std;
char s[130];
int check(int sta,int end){
	if(s[sta]<'A'||s[sta]>'Z')return 0;
	if(end-sta+1<=1)return 0;
	for(int i=sta+1;i<=end;i++)
		if(s[i]<'a'||s[i]>'z')
			return 0;
	return 1;
}
int trans(char c){
	if(c==' '||c=='.'||c==',')return 1;
	return 0;
}
int vis[130];
string get(int sta,int end){
	string a="";
	for(int i=sta;i<=end;i++)a+=s[i];
	return a;
}
vector<string>v; 
vector<char>vv;
int main(){
	//freopen("abbreviation.in","r",stdin);
	//freopen("abbreviation.out","w",stdout);
	while(gets(s)!=NULL){
		string ans="";
		int len=strlen(s),flg=0,lennow=0;
		for(int i=0;i<len;){
			int nx=i;
			for(int j=i;j<len;j++){
				if(trans(s[j])||j==len-1){
					nx=j+1;		
					if(!trans(s[j])&&j==len-1)j=len;
					int k=check(i,j-1);
					if(k&&s[j]==' '){
						v.push_back(get(i,j-1));
						vv.push_back(s[i]);
						break;
					}
					else if(k){
						v.push_back(get(i,j-1));
						vv.push_back(s[i]);
						if(v.size()>1){
							for(int i=0;i<vv.size();i++)ans+=vv[i];
							ans+=' ';
							ans+='(';
							for(int i=0;i<v.size()-1;i++){
								ans+=v[i];ans+=' ';
							}
							ans+=v[v.size()-1];
							ans+=')';
							if(j<len)ans+=s[j];
						}
						else if(v.size()==1){
							ans+=v[0];
							if(j<len)ans+=s[j];
						}
						else ans+=s[j];
						v.clear();vv.clear();
						break;
					}
					else {
						if(v.size()>1){
							for(int i=0;i<vv.size();i++)ans+=vv[i];
							ans+=' ';
							ans+='(';
							for(int i=0;i<v.size()-1;i++){
								ans+=v[i];ans+=' ';
							}
							ans+=v[v.size()-1];
							ans+=')';
							ans+=' ';
						}
						else if(v.size()==1){
							ans+=v[0];
							ans+=' ';
						} 
						v.clear();vv.clear();
						ans+=get(i,j-1);if(j<len)ans+=s[j];
						break;
					}
				}
			}
			i=nx;
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
}


