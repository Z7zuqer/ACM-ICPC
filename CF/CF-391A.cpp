#include<bits/stdc++.h>
using namespace std;
int cnt[9];
char s[100100];
int main(){
	scanf("%s",s);
	int len=strlen(s),maxm=1e9;
	for(int i=0;i<len;i++){
		if(s[i]=='B')cnt[0]+=1;//,maxm=min(maxm,cnt[0]);
		if(s[i]=='u')cnt[1]+=1;//,maxm=min(maxm,cnt[1]/2);
		if(s[i]=='l')cnt[2]+=1;//,maxm=min(maxm,cnt[2]);
		if(s[i]=='b')cnt[3]+=1;//,maxm=min(maxm,cnt[3]);
		if(s[i]=='a')cnt[4]+=1;//,maxm=min(maxm,cnt[4]/2);
		if(s[i]=='s')cnt[5]+=1;//,maxm=min(maxm,cnt[5]);
		//if(s[i]=='a')cnt[6]+=1,maxm=min(maxm,cnt[6]);
		if(s[i]=='r')cnt[7]+=1;//,maxm=min(maxm,cnt[7]);
	}
	for(int i=0;i<=7;i++){
		if(i==6)continue;
		if(i==1||i==4){
			maxm=min(maxm,cnt[i]/2);
			continue;
		}
		maxm=min(maxm,cnt[i]);
		
	}
	cout<<maxm<<endl;
}
