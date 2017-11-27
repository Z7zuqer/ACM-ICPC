#include<bits/stdc++.h>
using namespace std;
char s[1010];
int res[1010];
int main(){
	while(scanf("%s",s)!=EOF){
		memset(res,0,sizeof(res));
		int flg=0;
		int n=strlen(s);
		for(int i=0;s[i];i++)
			if(i<=n-2&&s[i]>='a'&&s[i]<='z'&&(s[i+1]=='(')){
				flg=1;
				res[i+1]=1;
			}
			else if(i>=1&&s[i]>='a'&&s[i]<='z'&&(s[i-1]==')')){
				flg=1;
				res[i-1]=1;
			}
			else if(s[i]==')'&&s[i+1]=='(')res[i]=res[i+1]=1;
			else if(s[i]==')'&&s[i+1]==')')res[i]=res[i+1]=1;
			else if(s[i]=='('&&s[i+1]=='(')res[i]=res[i+1]=1;
		stack<int>st;
		vector<pair<int,int> >v;
		for(int i=0;s[i];i++)
			if(s[i]=='('){
				st.push(i);
			}
			else if(s[i]==')'){
				int k=st.top();
				st.pop();
				if(i>k)v.push_back(make_pair(k,i));
				else v.push_back(make_pair(i,k));
			}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++){
			int st=v[i].first,e=v[i].second,flg=0;
			int k=0;
			if(res[st]||res[e]){
				for(int j=st+1;j<e;j++){
					if(s[j]=='+'&&!k){
						flg=1;
						res[st]=res[e]=1;
						break;
					}
					else if(s[j]=='('){
						k++;
					}
					else if(s[j]==')'){
						k--;
					}
				}
				if(!flg)res[st]=res[e]=0;
			}	
		}
		for(int i=0;s[i];i++)
			if(res[i])cout<<s[i];
			else if(s[i]>='a'&&s[i]<='z')cout<<s[i];
			else if(s[i]=='+')cout<<s[i];
		cout<<endl;
	}
}


