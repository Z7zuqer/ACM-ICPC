#include<bits/stdc++.h>
using namespace std;
#define LL long long 
const int maxn=1e5+7;
int NEXT[maxn];
char s[maxn];
LL ans[maxn]; 
vector<pair<int,LL> >v;
int main(){
	scanf("%s",s);
	NEXT[0]=0;
	for(int i=1,k=0;s[i];i++){
		while(k>0&&s[k]!=s[i])k=NEXT[k-1];
		if(s[i]==s[k])k++;
		NEXT[i]=k;
	}
	int len=strlen(s);
	for(int i=0;s[i];i++)ans[NEXT[i]]++;
	int k=NEXT[len-1];
	//cout<<NEXT[1]<<endl; 
	v.push_back({len,1});
	for(int i=len-1;i>=0;i--)
		if(NEXT[i-1]>=0)
			ans[NEXT[i-1]]+=ans[i];
	while(k){
		v.push_back({k,ans[k]+1});
		//ans[NEXT[k-1]]+=ans[k];
		k=NEXT[k-1];
		//cout<<k<<endl;
	}
	printf("%d\n",v.size());
	for(int i=v.size()-1;i>=0;i--)printf("%d %I64d\n",v[i].first,v[i].second);
}


