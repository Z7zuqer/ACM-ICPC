#include<bits/stdc++.h>
using namespace std;
int A[1010];
char s[1010];
int p[5]={1,10,100,1000,10000};
int getnum(string s){
	int k=0,siz=s.size();
	for(int i=0;i<siz;i++)
		k+=(s[i]-'0')*p[siz-i-1];
	return k;
}
int work(int k1,int k2,int n){
	if(k1>k2)return 0;
	if(k1<0)return 0;
	int k=0;
	for(int i=k1;i>=1&&i<=k2&&i<=n;i++)
		if(!A[i]){
			A[i]=1;
			k++;
		}
	return k;
}
int main(){
	int n;
	while(cin>>n&&n){
		memset(A,0,sizeof(A));
		scanf("%s",s);
		int len=strlen(s);
		string tmp="";
		int k1=-1,k2=-1,ans=0;
		for(int i=0;s[i];i++){
			if(i==len-1){
				tmp+=s[i];
				k2=getnum(tmp);
				if(k2==-1)ans+=work(k1,k1,n);//,cout<<ans<<endl;
				else if(k1==-1)ans+=work(k2,k2,n);//,cout<<ans<<endl;
				else ans+=work(k1,k2,n);//,cout<<ans<<endl;;
				//cout<<k1<<" "<<k2<<endl;
			}
			else if(s[i]!=','&&s[i]!='-')tmp+=s[i];
			else if(s[i]=='-'){
				k1=getnum(tmp);//cout<<k1<<endl;
				tmp="";
			}
			else if(s[i]==','){
				k2=getnum(tmp);
				tmp="";
				if(k2==-1)ans+=work(k1,k1,n);//,cout<<ans<<endl;
				else if(k1==-1)ans+=work(k2,k2,n);//,cout<<ans<<endl;
				else ans+=work(k1,k2,n);//,cout<<ans<<endl;;
				//cout<<k1<<" "<<k2<<endl;
				k1=k2=-1;
			}
		}
		//if(k2==-1)ans+=work(k1,k1,n);//,cout<<ans<<endl;
		//else if(k1==-1)ans+=work(k2,k2,n);//,cout<<ans<<endl;
		//else ans+=work(k1,k2,n);//,cout<<ans<<endl;;
		cout<<ans<<endl;
	}
}


