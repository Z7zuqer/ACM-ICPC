#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
int wa[maxn],wb[maxn],wv[maxn],wss[maxn];
int x[maxn],y[maxn],t[maxn];
int cmp(int r[],int a,int b,int len){
	return r[a]==r[b]&&r[a+len]==r[b+len];
}
void SA(char r[],int sa[],int n,int m){
	memcpy(x,wa,sizeof(wa));
	memcpy(y,wb,sizeof(wb));
	int i,j,p;
	for(i=0;i<m;i++)wss[i]=0;
	for(i=0;i<n;i++)wss[x[i]=r[i]]++;
	for(i=1;i<m;i++)wss[i]+=wss[i-1];
	for(i=n-1;i>=0;i--)sa[--wss[x[i]]]=i;
	for(j=1,p=1;p<n;j<<=1,m=p){
		for(p=0,i=n-j;i<n;i++)y[p++]=i;
		for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
		for(i=0;i<m;i++)wss[i]=0;
		for(i=0;i<n;i++)wss[wv[i]=x[y[i]]]++;
		for(i=1;i<m;i++)wss[i]+=wss[i-1];
		for(i=n-1;i>=0;i--)sa[--wss[wv[i]]]=y[i];
		memcpy(t,x,sizeof(x));
		memcpy(x,y,sizeof(y));
		memcpy(y,t,sizeof(t));
		x[sa[0]]=0;p=1;
		for(i=1;i<n;i++)x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
} 
char s[maxn];
int sa[maxn],rk[maxn];
int main(){
//	cout<<(int)" "<<endl;
	scanf("%s",s);
	int n=strlen(s),m=0;
	for(int i=0;i<n;i++)s[i+n]=s[i];n<<=1;
	SA(s,sa,n,276);
	//for(int i=0;i<n;i++)cout<<sa[i]<<" ";cout<<endl;
	for(int i=0;i<n;i++)if(sa[i]<n/2)printf("%c",s[sa[i]+n/2-1]);printf("\n");
}
