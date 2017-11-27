#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,p;
		scanf("%d%d",&n,&p);
		int rem=2*n+p;
		for(int i=1;i<n;i++){
			if(rem>0){
				printf("%d %d\n",i,i+1);
				rem--;
			}
		}
		for(int i=3;i<=n;i++){
			if(rem>0){
				printf("%d %d\n",1,i);
				rem--;
			}
		}
		for(int i=n-2;i>=2;i--){
			if(rem>0){
				printf("%d %d\n",n,i);
				rem--;
			}
		}
		int now=2,nown=n;
		while(rem>0){
			for(int i=n-now+1-2;i>=now+1;i--){
				if(rem>0){
					printf("%d %d\n",n-now+1,i);
					rem--;
				}
			}
			for(int i=now+2;i<=n-now+1;i++){
				if(rem>0){
					printf("%d %d\n",now,i);
					rem--;
				}
			}
			now++;
		}
	} 
}


