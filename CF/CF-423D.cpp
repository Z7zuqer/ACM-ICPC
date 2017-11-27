#include<bits/stdc++.h>
using namespace std;
int res[200101];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int max_num=(n-1)/k;max_num*=2;
	if((n-1)%k>=2)max_num+=2;
	else if((n-1)%k==1)max_num+=1;
	printf("%d\n",max_num);
	for(int i=1;i<=k;i++){
		printf("1 %d\n",i+1);
		res[i]=i+1;
	}
	n=n-k-1;
	int rem=k+2;
	int rem_q=1;
	while(n--){
		printf("%d %d\n",res[rem_q],rem);
		res[rem_q]=rem++;
		rem_q=rem_q%k+1;
	}
}

