#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int main(){
	int n;
	char s[290];
	cin>>n;
	scanf("%s",s);
	for(int i=0;i<n;i++){
		if(s[i]=='A')a++;
		else if(s[i]=='C')b++;
		else if(s[i]=='G')c++;
		else if(s[i]=='T')d++;
		else e++;
	}
	int mx=max(a,max(c,max(b,d)));
	int r1=mx-a;
	int r2=mx-b;
	int r3=mx-c;
	int r4=mx-d;
	int all=r1+r2+r3+r4;
	if(all>e){
		cout<<"==="<<endl;
		return 0;
	}
	if((e-all)%4!=0){
		cout<<"==="<<endl;
		return 0;
	}
	int now=1;
	for(int i=0;i<n;i++){
		if(s[i]=='?'&&r1)cout<<"A",r1--;
		else if(s[i]=='?'&&r2)cout<<"C",r2--;
		else if(s[i]=='?'&&r3)cout<<"G",r3--;
		else if(s[i]=='?'&&r4)cout<<"T",r4--;
		else if(s[i]!='?')cout<<s[i];
		else {
			if(now==1)cout<<"A";
			else if(now==2)cout<<"C";
			else if(now==3)cout<<"G";
			else if(now==4)cout<<"T";
			now=(now==4)?1:now+1;
		}
	}
}
