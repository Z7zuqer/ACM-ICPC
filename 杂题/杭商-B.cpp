#include<bits/stdc++.h>
using namespace std;
multiset<int>s[2];
int cnt=0;
int getv(int x,int flg){
	if(flg==0){//return maxv;
		multiset<int>::iterator it=s[x].end();
		it--;
		return *it;
	}
	else {//return minv;
		multiset<int>::iterator it=s[x].begin();
		return *it;
	}
}
void add(int k){
	cnt++;
	s[1].insert(k);
	if(cnt<=1){
		printf("%d\n",k);
		return ;
	}
	multiset<int>::iterator it;
	int num1=cnt/2,num2=cnt-num1;
	while(s[1].size()>num2){
		it=s[1].begin();
		s[0].insert(*it);
		s[1].erase(s[1].find(*it));
	}
	//cout<<num1<<" "<<num2<<endl;
	int x=getv(1,1),y=getv(0,0);
	while(x<y){
		s[0].erase(s[0].find(y));
		s[1].erase(s[1].find(x));
		s[1].insert(y);
		s[0].insert(x);
		x=getv(1,1),y=getv(0,0);
	}
	x=getv(1,1),y=getv(0,0);
	if(cnt&1)printf("%d\n",x);
	else {
		long long ans=1LL*getv(0,0)+getv(1,1);
		if(ans&1)
			printf("%.1f\n",1.0*ans/2);
		else 
			printf("%d\n",ans/2);
	}
}
void remove(int k){
	if(s[0].find(k)!=s[0].end()){
		cnt--;
		int num1=cnt/2,num2=cnt-num1;
		s[0].erase(s[0].find(k));
		while(s[0].size()<num1){
			int x=getv(1,1);
			s[1].erase(s[1].find(x));
			s[0].insert(x);
		}
	}
	else if(s[1].find(k)!=s[1].end()){
		cnt--;
		int num1=cnt/2,num2=cnt-num1;
		s[1].erase(s[1].find(k));
		while(s[1].size()<num2){
			int x=getv(0,0);
			s[0].erase(s[0].find(x));
			s[1].insert(x);
		}
	}
	else {
		puts("Wrong!");
		return ;
	}
	if(cnt==0)puts("Empty!");
	else if(cnt&1)printf("%d\n",getv(1,1));
	else {
		long long ans=1LL*getv(0,0)+getv(1,1);
		if(ans&1)
			printf("%.1f\n",1.0*ans/2);
		else 
			printf("%d\n",ans/2);
	}
}
void print(int x){
	multiset<int>::iterator it=s[x].begin();
	while(it!=s[x].end())printf("%d ",*(it++));
}
char p[101];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		cnt=0;
		int n;
		scanf("%d",&n);
		for(int i=0;i<2;i++)s[i].clear();
		for(int i=1;i<=n;i++){
			int x;
			scanf("%s%d",p,&x);
			if(p[0]=='a')add(x);
			if(p[0]=='r')remove(x);
//			cout<<"total: "<<endl;
//			print(0);cout<<endl;
//			print(1);cout<<endl;
		}
	}
}


