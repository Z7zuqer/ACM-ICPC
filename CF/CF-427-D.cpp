#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
char AFT[maxn<<1],s[maxn];
int LEN[maxn],len;
void trans(){
	int k=0;
	AFT[k++]='@';
	for(int i=0;s[i];i++){
		AFT[k++]='#';
		AFT[k++]=s[i]; 
	}
	AFT[k++]='#';
	len=k;
}
void manc(){
	int mx=0,wh=-1;
	for(int i=1;i<len;i++){
		if(mx>i)LEN[i]=min(mx-i,LEN[2*wh-i]);
		else LEN[i]=1;
		while(AFT[i-LEN[i]]==AFT[i+LEN[i]])LEN[i]++;
		if(i+LEN[i]>mx){mx=i+LEN[i];wh=i;}
	}
}
int main(){
	scanf("%s",s);
	trans();
	manc();
	for(int i=0;i<len;i++)cout<<LEN[i]<<" ";cout<<endl;
}


