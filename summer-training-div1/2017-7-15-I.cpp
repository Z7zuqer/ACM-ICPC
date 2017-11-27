#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	if(n%3==1){
		printf("1");
		n-=1;
		int now=2;
		while(n){
			printf("%d",now);
			n-=now;
			now=3-now;
		}
	}
	else {
		printf("2");
		n-=2;
		int now=1;
		while(n){
			printf("%d",now);
			n-=now;
			now=3-now;
		}
	}
}


