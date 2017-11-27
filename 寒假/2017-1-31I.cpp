#include<bits/stdc++.h>
using namespace std;
char s[1010];
queue<char>S,N; 
int main(){
	scanf("%s",s);
	for(int i=0;s[i];i++)
		S.push(s[i]);
	scanf("%s",s);
	for(int i=0;s[i];i++)
		N.push(s[i]);
	int ans=0;
	while(!S.empty()||!N.empty()){
		if(S.empty())
			N.pop();
		else if(N.empty())
			S.pop();
		else if(S.front()=='L'&&N.front()!='L')
			N.pop();
		else if(N.front()=='L'&&S.front()!='L')
			S.pop();
		else {
			S.pop();
			N.pop();
		}
		ans++;
	}
	cout<<ans<<endl;
}


