#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int aa=max(max(a,b),c);
	int bb=min(min(a,b),c);
	int cc=a+b+c-aa-bb;
	cout<<min(bb-aa*cc,bb-aa-cc)<<endl; 
}


