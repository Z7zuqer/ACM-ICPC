#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=1000000+107;
char s[maxn];
int NEXT[maxn],len;
void preNEXT(){
	NEXT[0]=0;
	for(int i=1,k=0;s[i];i++){
		while(k>0&&s[i]!=s[k])k=NEXT[k-1];
		if(s[i]==s[k])k++;
		NEXT[i]=k;
	}
}
vector<pair<int,int> >v;
int main(){
	int cas=1;
	while(scanf("%d%s",&len,s)!=EOF){
		if(len==0)break;
		preNEXT();
		v.clear();
		for(int i=0;i<len;i++){
			int tmp=NEXT[i];
			int k=i+1-tmp;
			if((i+1)%k==0&&(i+1)/k>1)v.push_back({i+1,(i+1)/k});
		}
		printf("Test case #%d\n",cas++);
		for(int i=0;i<v.size();i++)printf("%d %d\n",v[i].first,v[i].second);
		cout<<endl;
	}
}


