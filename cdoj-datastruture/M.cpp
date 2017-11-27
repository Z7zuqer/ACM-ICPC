#include<bits/stdc++.h>
using namespace std;
set<int>s;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		s.insert(x); 
	}
	//for(set<int>::iterator it=s.begin();it!=s.end();it++) cout<<*(it)<<endl;
	set<int>::iterator it;
	while(1){
		int flg=0;
		it=s.end();it--;
		int r=*it;
		//cout<<r<<endl;
		int rr=r;
		while(r>1){
			r>>=1;
			if(s.find(r)==s.end()){
				s.erase(rr);
				s.insert(r);
				flg=1;
				break;
			}
		}
		if(!flg)break;
	}
	it=s.end();it--;
	int r=*it;
	cout<<r<<endl;
}


