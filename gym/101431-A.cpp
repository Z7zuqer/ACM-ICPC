#include<bits/stdc++.h>
using namespace std;
string A[5]={"***","*.*","***","*.*","*.*"};
string B[5]={"***","*.*","***","*.*","***"};
string C[5]={"***","*..","*..","*..","***"};
string D[5]={"***","*.*","*.*","*.*","***"};
string E[5]={"***","*..","***","*..","***"};
int main(){
	string s;
	int n;
	cin>>n>>s;
	for(int i=0;i<5;i++){
		int siz=s.size();
		for(int j=0;j<siz;j++){
			if(s[j]=='A')cout<<A[i];
			else if(s[j]=='B')cout<<B[i];
			else if(s[j]=='C')cout<<C[i];
			else if(s[j]=='D')cout<<D[i];
			else if(s[j]=='E')cout<<E[i];
		}
		cout<<endl;
	}
}


