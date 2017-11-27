#include<bits/stdc++.h>
using namespace std;
const int maxn=801000;
bitset<900>b[maxn];
int main(){
	for(int i=1;i<=900;i++){
		int sta=i*i;
		for(int j=sta;j<maxn;j+=sta)
			b[j].set(i);
	}
	int T;
	scanf("%d",&T);
	while(T--){
		int m,ans=0;
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			bitset<900>tmp;
			for(int j=i;j<=m;j+=i){
				tmp|=b[m-j];
			}
			ans+=tmp.count();
		}
		printf("%d\n",ans);
	}
} 
