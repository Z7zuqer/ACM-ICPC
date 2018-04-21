#include<bits/stdc++.h>
using namespace std;
char s[101010],p[101010];
int ans[101010];
string name[107];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	int maxv=-1,x=-1;
	for(int i=1;i<=m;i++){
		cin>>name[i];
		scanf("%s",p);
		for(int j=0;s[j];j++){
			if(s[j]==p[j])
				ans[i]++;
		}
		if(maxv<ans[i]){
			maxv=ans[i];
			x=i;
		}
		else if(maxv==ans[i]){
			if(name[x]>name[i])
				x=i;
		}
	}
	cout<<name[x]<<endl;
	printf("%.2f\n",100.0*maxv/n);
}


