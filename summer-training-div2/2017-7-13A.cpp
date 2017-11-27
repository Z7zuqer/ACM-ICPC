#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	int r1=0,r2=0,siz=a.size();
	for(int i=0;i<siz;i++)
		if(a[i]=='0')r1++;
		else r2++;
	cout<<min(r1,r2)<<endl;
}


