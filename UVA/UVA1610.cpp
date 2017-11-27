#include<bits/stdc++.h>
using namespace std;
struct node{
	char s[33];
}A[1010];//m,n;
bool cmp(node m,node n){
	return strcmp(n.s,m.s)==1?1:0;//;//<strcmp(n.s);
}
char s1[35],s2[35];
//int flg[35];
int main(){
	int n;
	//cout<<
	while(scanf("%d",&n)==1&&n){
		//memset(flg,0,sizeof(flg));
		for(int i=1;i<=n;i++)scanf("%s",A[i].s);
		sort(A+1,A+1+n,cmp);
		int wh=n/2;
		strcpy(s1,A[wh].s);
		strcpy(s2,A[wh+1].s);
		int l1=strlen(s1),l2=strlen(s2);
		for(int i=0;i<l1&&i<l2;i++)
			if(s1[i]!=s2[i]){
				if(s1[i]+1==s2[i]){
					cout<<s1[i];
				}
				else {
					printf("%c",s1[i]+1);
					break;
				}
			}
			else cout<<s1[i];
		cout<<endl;
	}
}


