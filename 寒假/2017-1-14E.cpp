#include<bits/stdc++.h>
using namespace std;
int A[27],B[27];//A before B now=======whether use
char s[100010];
char v[30];
char a,b;
bool cmp(char x,char y){
	return x<y;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		scanf("%s",s);
		int num=0;//count
		for(int i=0;s[i];i++){
			if(!A[s[i]-'a']){
				v[num]=s[i];
				A[s[i]-'a']=1;
				num++;
			}
		}
		sort(v,v+num,cmp);
		//cout<<v[0]<<endl;
		for(int i=0;i<num;i++)A[v[i]-'a']=i;
		int wh=0,flg=0;
		for(int i=0;s[i];i++){
			//cout<<v[wh]<<" "<<s[i]<<endl;
			if(v[wh]==s[i]){
				wh++;
				B[s[i]-'a']=1;
			}
			else if(B[s[i]-'a'])continue;
			else {
				//cout<<v[wh]<<endl;
				//cout<<i<<endl;
				flg=1;
				a=v[wh];
				b=s[i];
				break;
			}
		}
		//cout<<a<<" "<<b<<endl;
		for(int i=0;s[i];i++){
			if(flg&&s[i]==a)printf("%c",b);
			else if(flg&&s[i]==b)printf("%c",a);
			else printf("%c",s[i]);
		}
		printf("\n");
	}
}


