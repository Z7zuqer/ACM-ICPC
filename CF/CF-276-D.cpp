#include<bits/stdc++.h>
using namespace std;
const int maxn=2000000+107;
int nxt[maxn],A[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),nxt[A[i]]=A[i];
	int pre=-1;
	for(int i=1;i<=2000000;i++){
		if(nxt[i])pre=i;
		else nxt[i]=pre;
	}
	int maxv=0;
	for(int i=1;i<=n;i++){
		for(int j=A[i];j<=2000000;j+=A[i]){
			int num=nxt[j-1];
			cout<<num<<endl;
			if(num<j-A[i]+1||num==-1)continue;
			int k=A[i]-j+num;if(k==A[i])k=0;
			maxv=max(maxv,k);
		}
	}
	printf("%d\n",maxv);
}


