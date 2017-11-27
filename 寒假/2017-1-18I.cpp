#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
bitset<maxn>A[maxn<<2];
bitset<maxn>B[maxn<<2];
bitset<maxn>C;
char s1[maxn],s2[maxn],rem[maxn];
int req[maxn<<2];//4000hang 1000gezifu
int n,m;
set<int>s;
set<int>::iterator it;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		s.insert(i);
		scanf("%s%s",s1,s2); 
		for(int j=0;j<n;j++)if(s1[j]=='1')A[i].set(j);
		for(int j=0;j<n;j++)if(s2[j]=='1')B[i].set(j);
	}
	scanf("%s",rem);
	for(int i=0;i<n;i++)if(rem[i]=='1')C.set(i);
	while(1){
		int flg=0;
		for(it=s.begin();it!=s.end();it++){
			int i=(*it);//cout<<i<<endl;
			if(i<0||i>=m)break;
			if((C&A[i])==A[i]){
				flg=1;
				C|=B[i];
				s.erase(i);
			}
		}
		if(!flg)break;
	}
	for(int i=0;i<n;i++)cout<<C[i];cout<<endl;
}


