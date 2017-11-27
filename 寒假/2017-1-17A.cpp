#include<bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
const int maxn=200010;
int n,k,l;
int fa1[maxn],fa2[maxn];
map<ULL,int>mp;
int find1(int x){
	return fa1[x]==x?x:fa1[x]=find1(fa1[x]);
}
int find2(int x){
	return fa2[x]==x?x:fa2[x]=find2(fa2[x]);
}
int uni1(int x,int y){
	int a=find1(x),b=find1(y);
	if(a!=b)fa1[b]=a;
}
int uni2(int x,int y){
	int a=find2(x),b=find2(y);
	if(a!=b)fa2[b]=a;
}
int main(){
	scanf("%d%d%d",&n,&k,&l);
	int a,b;
	for(int i=0;i<=n;i++)fa1[i]=fa2[i]=i;
	for(int i=0;i<k;i++){
		scanf("%d%d",&a,&b);
		uni1(a,b);
	}
	for(int i=0;i<l;i++){
		scanf("%d%d",&a,&b);
		uni2(a,b);
	}
	for(int i=1;i<=n;i++)fa1[i]=find1(i),fa2[i]=find2(i);
	for(int i=1;i<=n;i++)
		mp[(ULL)((ULL)fa1[i]*12345678+(ULL)fa2[i])]++;
	for(int i=1;i<=n;i++)
		if(i!=n)printf("%d ",mp[(ULL)((ULL)fa1[i]*12345678+(ULL)fa2[i])]);
		else printf("%d\n",mp[(ULL)((ULL)fa1[i]*12345678+(ULL)fa2[i])]);
}


