#include<bits/stdc++.h>
using namespace std;
struct node{
	int pos;
	char c;
	int cnt;
};
int n;
char str[10101];
int ans[10101],r[10101];
stack<node>s;
int work(char a,char b){
	if(abs(b-a)==abs('a'-'A'))return 1;
	return 0;
}
int main(){
	int cnt=1;
	scanf("%d",&n);
	scanf("%s",str);
	for(int i=0;str[i];i++){
		if(str[i]>='a'&&str[i]<='z')
			r[i]=cnt++;//,cout<<r[i]<<" "<<str[i]<<endl;
		else
			r[i]=-1;
		//cout<<r[i]<<endl;
	}
	for(int i=0;str[i];i++){
		if(!s.empty()&&work(str[i],s.top().c)){
			//cout<<str[i]<<" "<<s.top().c<<endl;
			if(r[s.top().pos]==-1)
				ans[s.top().pos]=r[i];
			else 
				ans[i]=r[s.top().pos];
			s.pop();
		}
		else 
			s.push({i,str[i],r[i]});
		//cout<<s.size()<<endl;
	}
	if(!s.empty())
		cout<<"Impossible"<<endl;
	else {
		for(int i=0;str[i];i++)
			if(ans[i])
				cout<<ans[i]<<" ";
		cout<<endl;
	}
}
