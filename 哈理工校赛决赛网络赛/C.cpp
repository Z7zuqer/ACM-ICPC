#include<bits/stdc++.h>
using namespace std;
void print(int x){
	for(int i=1;i<=x;i++)printf(" ");
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			print(n-1-i);
			for(int j=1;j<=i*2+1;j++)printf("*");
			puts("");
		}
	}
}


