#include<bits/stdc++.h>
using namespace std;
int face[7][7];
int check(string a.string b,sttring c,string d){
	if(a!=b)return 0;
	if(c!=d)return 0;
	
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		string r[5];
		for(int i=1;i<=6;i++)
			for(int j=1;j<=4;j++)
				scanf("%d",&face[i][j]);
		int flg=0;
		for(int i=1;i<=6&&!flg;i++){
			int fflg=0;
			for(int j=1;j<=4&&!fflg;j++)
				if(face[i][j]!=face[i][1])fflg=1;
			flg|=fflg;
		}
		if(!flg)puts("YES");
		else {
			for(int i=1;i<=4;i++){
				r[i]="";
				for(int j=1;j<=6;j++){
					r[i]+=(char)('0'+face[j][i]);
				}
			}
			//cout<<r[1]<<" "<<r[2]<<" "<<r[3]<<" "<<r[4]<<endl;
			if(check(r[1],r[2],r[3],r[4])||check(r[2],r[3],r[4],r[1])||check(r[3],r[4],r[1],r[2])||check(r[1],r[4],r[3],r[2]))puts("YES");
			else puts("NO");
		}
	}
}


