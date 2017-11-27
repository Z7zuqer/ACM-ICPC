#include<bits/stdc++.h>
using namespace std;
struct sta{
	int wh,dir,sig,ans,ansdir;
}a[1000010];
bool cmp(sta m,sta n){
	return m.wh<n.wh;
}
struct lst{
	int wh,dir;
}b[1000010];
bool cmp1(lst m,lst n){
	return m.wh<n.wh;
}
bool cmp2(sta m,sta n){
	return m.sig<n.sig;
}
map<int,int>mp;
int main(){
	int T,cas=1;
	cin>>T;
	while(T--){
		mp.clear();
		int t,l,n;
		char s[2];
		scanf("%d%d%d",&l,&t,&n);
		for(int i=1;i<=n;i++){
			scanf("%d%s",&a[i].wh,s);
			if(s[0]=='L')a[i].dir=-1;
			if(s[0]=='R')a[i].dir=1;
			a[i].sig=i;
			b[i].wh=a[i].wh+a[i].dir*t;
			b[i].dir=a[i].dir;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp1);
		for(int i=1;i<=n;i++){
			a[i].ans=b[i].wh;
			if(!mp[b[i].wh]){
				mp[b[i].wh]=i;
				a[i].ansdir=b[i].dir;
			}
			else {
				a[i].ansdir=0;
				a[mp[b[i].wh]].ansdir=0;
			}
		}
		sort(a+1,a+1+n,cmp2);
		printf("Case #%d:\n",cas++);
		for(int i=1;i<=n;i++){
			if(a[i].ans>l||a[i].ans<0){
				cout<<"Fell off"<<endl;
				continue;
			}
			printf("%d ",a[i].ans);
			if(a[i].ansdir==0)printf("Turning\n");
			if(a[i].ansdir==-1)printf("L\n");
			if(a[i].ansdir==1)printf("R\n");
		}
		cout<<endl;
	}
} 
