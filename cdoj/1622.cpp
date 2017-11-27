#include<bits/stdc++.h>
using namespace std;
#define LL long long
int len(LL k){
	int cnt=0;
	while(k)cnt++,k/=10;
	return cnt;
}
int main(){
	LL r=1;
	for(int i=1;i<=100;i++){
		r*=(LL)i;
		cout<<r<<"==="<<len(r)<<endl;
	}
}


