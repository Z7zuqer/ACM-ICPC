#include<bits/stdc++.h>
using namespace std;
char str[101];
int num[1010],t;
long long d;
int main(){
	scanf("%d",&t);
	while(t--){
		int ans=0;
		long long tmp=0;
		set<long long>s;
		scanf("%s%lld",str,&d);
		int n=strlen(str);
		sort(str,str+n);
		do{
			tmp=0;
			for(int i=0;i<n;i++)tmp=tmp*10+str[i]-'0';
			if(s.count(tmp)==0&&tmp%d==0){
				ans++;
				s.insert(tmp);
			}
		}while(next_permutation(str,str+n));
		cout<<ans<<endl;
	}
}
