#include<bits/stdc++.h>
using namespace std;
int main(){
	int s,x1,x2,t2,t1,p,d,req;
	cin>>s>>x1>>x2>>t2>>t1>>p>>d;
	if(x1<x2){
		if(d==1)
			if(p>x1)req=(s-p+x2+s)*t2;
			else req=(x2-p)*t2;
		else
			req=(p+x2)*t2;
	}
	else if(x1>x2){
		if(d==1)
			req=(s*2-p-x2)*t2;
		else 
			if(p<x1)req=(p+s*2-x2)*t2;
			else req=(p-x2)*t2;
	}
	cout<<min(req,abs(x2-x1)*t1)<<endl;
}
