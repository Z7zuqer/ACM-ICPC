#include<bits/stdc++.h>
using namespace std;
int cnt[12]={1,0,0,0,1,0,1,0,2,1};
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,ans=0;
		scanf("%d%d",&a,&b);
		for(int i=a;i<=b;i++){
			int k=i;
			while(k){
				ans+=cnt[k%10];
				k/=10;
			}
		}
		printf("%d\n",ans);
	}
}


