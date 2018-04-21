#include<bits/stdc++.h>
using namespace std;
string res[1010]={"algorithm", "bitset", "cctype", "cerrno", "clocale", "cmath", "complex", "cstdio", "cstdlib", "cstring", "ctime", "deque", "exception", "fstream", "functional", "limits", "list", "map", "iomanip", "ios", "iosfwd", "iostream", "istream", "ostream", "queue", "set", "sstream", "stack", "stdexcept", "streambuf", "string", "utility", "vector", "cwchar", "cwctype"};
map<string,int>mp;
int main(){
	for(int i=0;i<1010;i++){
		if(res[i].size()<=0)break;
		mp[res[i]]=1;
	}
	int T;
	scanf("%d",&T);
	while(T--){
		string k;
		cin>>k;
		if(mp[k])puts("Qian");
		else puts("Kun");
	}
}


