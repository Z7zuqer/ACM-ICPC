#include<bits/stdc++.h>
using namespace std;
int main(){
	int x;long long ans=0;
	while(scanf("%d",&x)!=EOF){
		char c;
		scanf("%c",&c);
		if(c=='+')ans+=x,ans%=10000;
		else if(c=='\n'){
			ans+=x;ans%=10000;
			break;
		}
		else {
			int flg=0;long long pre=x;
			while(c=='*'){
				int a;
				scanf("%d",&a);
				pre=pre*1LL*a%10000;
				scanf("%c",&c);
				if(c=='\n'){
					flg=1;
					break;
				}
			}
			ans+=pre;ans%=10000;
			if(flg)break;
		}
	}
	printf("%lld\n",ans%10000);
}


