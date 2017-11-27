#include<bits/stdc++.h>
using namespace std;
char A[4010],B[4010];
int cnt[29];
int work(char s[],int sta,int end){
	int k=0,cnt_tmp[30];
	for(int i=0;i<26;i++)cnt_tmp[i]=cnt[i];
	for(int i=sta;i<=end;i++)
		if(cnt_tmp[s[i]-'a']>=1)cnt_tmp[s[i]-'a']--;
		else return 0;
	return 1;	
}
int main(){
	scanf("%s%s",A,B);
	int len_A=strlen(A);
	int len_B=strlen(B);
	for(int i=0;i<len_B;i++)cnt[B[i]-'a']++;
	int ans=0;
	for(int i=0;i<len_A;i++)
		for(int j=len_A-1;j>=i;j--)
			if(j-i+1<=ans)continue;
			else if(work(A,i,j))ans=max(ans,j-i+1);
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<len_B;i++)
		for(int j=len_B;j>=i;j--)
			if(j-i+1<=ans)continue;
			else if(work(B,i,j))ans=max(ans,j-i+1);
	cout<<ans<<endl;
}
