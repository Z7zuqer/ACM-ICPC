#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
struct node{
	int src,sig;
	bool operator>(const node &a)const{
		if(a.src==src)return sig<a.sig;
		return src<a.src;
	}
	bool operator<(const node &a)const{
		if(a.src==src)return sig<a.sig;
		return src>a.src;
	}
};
int num[maxn],lst[maxn];
set<node>s;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		s.clear();
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)s.insert({0,i}),num[i]=0;
		int maxm=0,wh=1,flg=0,res=0;
		for(int i=1;i<=q;i++){
			int x,p;
			scanf("%d%d",&x,&p);
			s.erase(node{num[x],x});
			num[x]+=p;
			s.insert(node{num[x],x});
			int k1=(s.begin())->sig,k2=s.begin()->src;
			/*if(k2>maxm){
				
			}*/
			if(k1!=wh){
				res=i;
				wh=k1;
			}
			//cout<<k1<<"==="<<k2<<endl;
			//cout<<"NO:"<<" "<<i<<"===="<<wh<<" "<<maxm<<endl; 
		}
		//for(int i=1;i<=q;i++)cout<<win[i]<<endl;
		cout<<res<<endl;
	}
}


