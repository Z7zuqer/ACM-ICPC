#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,x,s=0,flg=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			s^=x;
			if(x!=1)flg=1;
		}
		if((s!=0&&flg)||(s==0&&!flg))cout<<"John"<<endl;
		else cout<<"Brother"<<endl;
	}
}
