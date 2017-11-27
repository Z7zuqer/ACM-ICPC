#include<bits/stdc++.h>
using namespace std;
char s[110];
int kr,kb,ky,kg,flg;
int r=-1,b=-1,y=-1,g=-1;
int main(){
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]=='B')b=i;
		if(s[i]=='R')r=i;
		if(s[i]=='Y')y=i;
		if(s[i]=='G')g=i;
	}
	for(int i=0;i<len;i++){
		if(s[i]=='!'){
			if(r!=-1&&(i%4)==(r%4))kr++;
			else if(b!=-1&&(i%4)==(b%4))kb++;
			else if(y!=-1&&(i%4)==(y%4))ky++;
			else if(g!=-1&&(i%4)==(g%4))kg++;
			if(r==-1)kr++,r=i;
			else if(b==-1)kb++,b=i;
			else if(y==-1)ky++,y=i;
			else if(g==-1)kg++,g=i;
		}
	}
	cout<<kr<<" "<<kb<<" "<<ky<<" "<<kg<<endl;
}


