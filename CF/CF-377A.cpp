#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	for(int i=1;;i++){
		if((i*a)%10==b||(i*a)%10==0)return 0*printf("%d\n",i);
	}
}


