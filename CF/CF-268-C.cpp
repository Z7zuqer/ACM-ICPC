#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	if(n<4)return 0*printf("NO\n");
	puts("YES");
	if(n&1){
		puts("5 - 1 = 4");
		puts("4 - 2 = 2");
		puts("2 * 4 = 8");
		puts("8 * 3 = 24");
		for(int i=6;i<=n;i+=2){
			printf("%d - %d = 1\n",i+1,i);
			printf("1 * 24 = 24\n");
		}
	}
	else {
		puts("1 * 2 = 2");
		puts("2 * 3 = 6");
		puts("4 * 6 = 24");
		for(int i=5;i<=n;i+=2){
			printf("%d - %d = 1\n",i+1,i);
			printf("1 * 24 = 24\n");
		}
	}
}


