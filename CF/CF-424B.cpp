#include<bits/stdc++.h>
using namespace std;
map<char,char>mp;
char A[31],B[31],C[1500];
int main(){
	scanf("%s%s",A,B);
	for(int i=0;i<26;i++)
		mp[A[i]]=B[i];
	scanf("%s",C);
	for(int i=0;C[i];i++){
		if(C[i]>='a'&&C[i]<='z'){
			printf("%c",mp[C[i]]);
		}
		else if(C[i]>='A'&&C[i]<='Z'){
			printf("%c",mp[C[i]-'A'+'a']-'a'+'A');
		}
		else printf("%c",C[i]);
	}
	cout<<endl;
}


