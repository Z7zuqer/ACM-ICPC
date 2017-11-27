#include<bits/stdc++.h>
using namespace std;
int n,k,a,b,flg=1;
int main(){
	cin>>n>>k>>a>>b;
	if(a<b)flg=0;
	int re1=max(a,b),re2=a+b-re1;
	int div=re1/(re2+1);
	if(re1%(re2+1))div++;
	int rem=re1%(re2+1);
	if(k<div){
		cout<<"NO"<<endl;
		return 0;
	}
	int num=1;
	while(rem){
		if((num%(div+1)))
			if(!flg)cout<<"B";
			else cout<<"G";
		else {
			re2--;
			rem--;
			if(!flg)cout<<"G";
			else cout<<"B";
		}
		num++;
	}
	if(re1%(re2+1))div--;
	int rem2=num-1;
	while(re2){
		if((num-rem2)%(div+1))
			if(!flg)cout<<"B";
			else cout<<"G";
		else {
			if(!flg)cout<<"G";
			else cout<<"B";
			re2--;
		}
		num++;
	}
	for(int i=num;i<=n;i++)
		if(!flg)cout<<"B";
		else cout<<"G";
	cout<<endl;
}

