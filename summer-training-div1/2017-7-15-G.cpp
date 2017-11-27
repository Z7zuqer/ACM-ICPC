#include<bits/stdc++.h>
using namespace std;
int po[7]={1,2,4,8,16,32,64};
int main(){
	int n;
	scanf("%d",&n);
	if(n<=6)return 0*printf("2112\n");
	int r=0;
	for(int i=0;i<7;i++)
		if(n<po[i]){
			r=i-1;
			break;
		}
	for(int i=1;i<=po[r];i++)printf("12");
	printf("2112\n");
}
