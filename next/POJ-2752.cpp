#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=400000+7;
int NEXT[maxn],len;
char s[maxn];
void preNEXT(){
	NEXT[0]=0;
	for(int i=1,k=0;s[i];i++){
		while(k>0&&s[i]!=s[k])k=NEXT[k-1];
		if(s[i]==s[k])k++;
		NEXT[i]=k;
	}
}
vector<int>v;
int main(){
	while(scanf("%s",s)!=EOF){
		preNEXT();
		v.clear();
		len=strlen(s);
		int k=NEXT[len-1];
		v.push_back(len);
		if(k>0)v.push_back(k);
		while(k>0){
			k=NEXT[k-1];
			if(k>0)v.push_back(k);
		}
		for(int i=v.size()-1;i>=0;i--)printf("%d ",v[i]);cout<<endl;
	}
}


