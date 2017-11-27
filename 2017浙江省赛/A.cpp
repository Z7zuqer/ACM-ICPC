#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int cnt1=0,cnt2=0;
		while(n--){
			int x;
			cin>>x;
			if(x==1)cnt1++;
			if(x==2)cnt2++;
			if(x==3)cnt1++,cnt2++;
			if(x==4)cnt1--,cnt2--;
		}
		if(cnt1>cnt2)cout<<"Kobayashi"<<endl;
		else if(cnt1<cnt2)cout<<"Tohru"<<endl;
		else cout<<"Draw"<<endl;
	} 
}


