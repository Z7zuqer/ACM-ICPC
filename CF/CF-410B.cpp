#include<bits/stdc++.h>
using namespace std;
int n;
char s[51][51];
char ss[51];
void change(int len){
	char sss[51];
	for(int i=1;i<len;i++){
		sss[i-1]=ss[i];
	}
	sss[len-1]=ss[0];
	sss[len]='\0';
	memcpy(ss,sss,sizeof(sss));
}
int cal(char s2[],char s1[],int len){
	int cnt=0;char ss1[51];
	strcpy(ss1,s1);
	while(strcmp(ss1,s2)!=0){
		//cout<<ss1<<endl;
		char sss[51];
		for(int i=1;i<len;i++){
			sss[i-1]=ss1[i];
		}
		sss[len-1]=ss1[0];
		sss[len]='\0';
		strcpy(ss1,sss);
		cnt++;
		if(cnt>len)return -1;
	}
	//cout<<endl;
	return cnt;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]);
	}
	int len=strlen(s[1]);
	for(int i=0;i<len;i++){
		ss[i]=s[1][i];
	}
	ss[len]='\0';
	int ans=1e9;
	for(int i=0;i<len;i++){
		int k=0;
		for(int j=1;j<=n;j++){
			int tmp=cal(ss,s[j],len);
			if(tmp==-1)return 0*printf("-1\n");
			k+=tmp;
		}
		ans=min(ans,k);
		change(len);
	}
	cout<<ans<<endl;
}


