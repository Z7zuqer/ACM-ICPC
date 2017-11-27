#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[150000],ans[500];
multiset<LL>s;
int main(){
	int m;
	while(~scanf("%d",&m)){
		s.clear();
		for(int i=1;i<=m;i++)scanf("%lld",&A[i]),s.insert(A[i]);
		int n=-1;
		for(int i=1;;i++){
			if(i*(i+1)/2>=m){
				n=i;
				break;
			}
		}

		for(int i=1;i<=n;i++){
			ans[i]=(*(s.begin()));
			s.erase(s.begin());
			for(int j=1;j<i;j++){
				s.erase(s.find(ans[i]+ans[j]));
			}
		}
		printf("%d\n",n);
		for(int i=1;i<=n;i++)if(i!=n)printf("%lld ",ans[i]);else printf("%lld\n",ans[i]);
	}
}
