#include<bits/stdc++.h>
using namespace std;
char s[1000];
struct node{
	int l,r;
}re[1010];
int cnt=0;
int cmp(node m,node n){
	if(m.l==n.l)return m.r<n.r;
	return m.l<n.l;
}
vector<pair<int,int> >v;
int main(){
	int L=-32768,R=32767;
	while(gets(s)!=NULL){
		int l=L,r=R,len=strlen(s);
		int k=0,i=0,flg=0;
		for(;s[i];i++){
			if(s[i]=='>')flg=0;
			else if(s[i]=='<')flg=1;
			else if(s[i]>='0'&&s[i]<='9')break;
		}
		for(int u=i;s[u]>='0'&&s[u]<='9';u++)
			k=k*10+s[u]-'0';
		if(s[i-1]=='-')k=-k;
		if(flg)r=min(r,k);
		else l=max(l,k);
		int rem=0;
		for(int u=i;s[u];u++)if(s[u]=='&'){
			i=u;rem=1;
			break;
		}
		int kk=0,flg_1=0;
		if(rem){
			for(int u=i;s[u]&&s[u]<'0'&&s[u]>'9';u++){
				if(s[u]=='>')flg_1=0;
				else if(s[u]=='<')flg_1=1;
				i=u;
			}
			for(int u=i;u<len;u++){
				if(s[u]>='0'&&s[u]<='9'){
					kk=kk*10+s[u]-'0';
				}
				else break;
			}
			if(s[i-1]=='-')kk=-kk;
			if(flg_1)r=min(r,kk);
			else l=max(l,kk);
		}
		if(r<l)return 0*printf("false\n");
		re[cnt++]={l,r};
	}
	sort(re,re+cnt,cmp);
	if(cnt==1){
		printf("x <= %d && x >= %d\n",re[0].r,re[0].l);
		return 0;
	}
	int l=re[0].l,r=re[0].r,flg=1;
	for(int i=1;i<cnt;i++){
		if(re[i].l<=r)flg=0,r=max(r,re[i].r);
		else {
			flg=1;
			v.push_back({l,r});
			l=re[i].l;r=re[i].r;
		}
	}
	if(!flg)v.push_back({l,r});
	if(v.size()==1&&v[0].first==L&&v[0].second==R)return 0*printf("true\n");
	for(int i=0;i<v.size();i++){
		printf("x <= %d && x >= %d",v[i].second,v[i].first);
		if(i!=v.size()-1)printf(" ||\n");
		else cout<<endl;
	}
}
