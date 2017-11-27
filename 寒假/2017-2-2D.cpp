#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,cnt=1;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		if(i>=k)printf("0 ");
		else printf("%d ",cnt*((i%2==1?1:-1)));
		if(i%2==0)cnt++;
	}
	cout<<endl;
}


