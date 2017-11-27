#include<bits/stdc++.h>
using namespace std;
#define LL long long
char s[100010];
int main(){
	scanf("%s",s+1);
	LL a1=0,a2=0,b1=0,b2=0;
	for(int i=1;s[i];i++){
		if(s[i]=='a'){
			if(i&1)a1++;
			else a2++;
		}
		if(s[i]=='b'){
			if(i&1)b1++;
			else b2++;
		}
	}
	LL ans1=a1*a2+b1*b2;
	LL ans2=a1*(a1-1)/2+a2*(a2-1)/2+b1*(b1-1)/2+b2*(b2-1)/2+b1+b2+a1+a2;
	cout<<ans1<<" "<<ans2<<endl;
}


