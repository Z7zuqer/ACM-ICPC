#include<bits/stdc++.h>
using namespace std;
char ss[210];
int check(int s,int e){
	if((e-s+1)&1)return 0;
	int sta1=s;
	int sta2=(e-s+1)/2+s;
	for(int i=0;i<(e-s+1)/2;i++)
		if(ss[sta1+i]!=ss[sta2+i])
			return 0;
	return 1;
}
int main(){
	scanf("%s",ss);
	int ans=0,len=strlen(ss);
	for(int i=0;i<len-1;i++)
		for(int j=i+1;j<len-1;j++)
			if(check(i,j))
				ans=max(ans,j-i+1);
	cout<<ans<<endl;
}


