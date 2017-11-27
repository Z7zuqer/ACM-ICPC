#include<bits/stdc++.h>
using namespace std;
map<string,int>mpp;
map<string,string>mp; 
int main(){
	string a,b,c,d;
	cin>>a>>b;
	mpp[a]=1;
	mpp[b]=1;
	int n;
	scanf("%d",&n);
	cout<<a<<" "<<b<<endl;
	for(int i=1;i<=n;i++){
		cin>>c>>d;
		if(mpp[c]){
			if(a==c)a=d;
			else b=d;
			mpp[d]=1;
		}
		cout<<a<<" "<<b<<endl;
	}
}


