#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,num[1200];
	node(){
		memset(num,0,sizeof(num));
		l=1;
	}
	friend node operator*(int k,node &a){
		node res;res.l=a.l+1;
		for(int i=1;i<=a.l;i++){
			res.num[i]+=a.num[i]*k;
			res.num[i+1]+=res.num[i]/10;
			res.num[i]%=10;
		}
		if(res.num[res.l]==0)res.l--;
		return res;
	}
	friend node operator-(node m,node n){
		node res;res.l=max(m.l,n.l);
		for(int i=1;i<=res.l;i++){
			res.num[i]=m.num[i]-n.num[i];
			while(res.num[i]<0)res.num[i]+=10,m.num[i+1]--;
		}
		while(res.l>1&&res.num[res.l]==0)res.l--;
		return res;
	}
	friend node operator+(node &a,int k){
		node res=a;res.num[1]+=k;
		for(int i=1;i<=res.l;i++){
			if(res.num[i]>=10)res.num[i]-=10,res.num[i+1]++;
			else break;
		}
		if(res.num[res.l+1])res.l++;
		return res;
	}
	void print(){
		for(int i=l;i>=1;i--)printf("%d",this->num[i]);
	}
}ans[105];
int n;
int main(){
	scanf("%d",&n);sw
	ans[1]=ans[1]+3;
	ans[2]=ans[2]+8;
	if(n<=2){
		ans[n].print();
		return 0;
	}
	for(int i=3;i<=n;i++)ans[i]=3*ans[i-1]-ans[i-2];
	node sta=3*ans[n-1]-2*ans[n-2];sta=sta+(-2);
	sta.print();cout<<endl;
}

