#include<bits/stdc++.h>
using namespace std;
int main(){
	int x1,x2,y1,y2,w,h;
	freopen("anniversary.in","r",stdin);
	freopen("anniversary.out","w",stdout);
	cin>>w>>h>>x1>>y1>>x2>>y2;
	if(x1==x2)cout<<0<<" "<<y1<<" "<<w<<" "<<y2<<endl;
	else if(y1==y2)cout<<x1<<" "<<0<<" "<<x2<<" "<<h<<endl;
	else {
		if(y1>y2)cout<<min(x1,x2)<<" "<<0<<" "<<max(x1,x2)<<" "<<h<<endl;
		else cout<<min(x1,x2)<<" "<<h<<" "<<max(x1,x2)<<" "<<0<<endl;
	}
}


