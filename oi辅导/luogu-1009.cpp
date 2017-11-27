#include<bits/stdc++.h>
using namespace std;
int n;
char a[1010],b[1010],c[1010];
void add(){
	int lena=strlen(a),lenb=strlen(b),maxlen=max(lena,lenb);
	for(int i=0;i<maxlen;i++){
		if(lena-i-1<0||lenb-i-1<0)break;
		c[i]=a[lena-i-1]-'0'+b[lenb-1-i];
	} 
	if(lena>lenb)
		for(int i=lenb;i<lena;i++)c[i]=a[lena-1-i];
	else 
		for(int i=lena;i<lenb;i++)c[i]=b[lenb-i-1];
	for(int )
}
string mul(string a,string b){
	
}
int main(){
	sscanf
}


