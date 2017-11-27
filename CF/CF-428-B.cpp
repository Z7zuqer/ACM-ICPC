#include<bits/stdc++.h>
using namespace std;
int A[110];
int mp[10010][9];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)scanf("%d",&A[i]); 
	int rem2=n*2,rem4=n;
	int req2=0,req1=0;
	for(int i=1;i<=k;i++){
		int v=A[i];
		int cnt4=v/4;
		int rem=v%4;
		if(rem4>cnt4)rem4-=cnt4,cnt4=0;
		else cnt4-=rem4,rem4=0;
		int all=rem+cnt4*4;
		int cnt2=0;
		if(all&1)req1++;
		cnt2=all/2;
		if(rem2>cnt2)rem2-=cnt2,cnt2=0;
		else cnt2-=rem2,rem2=0;
		//cout<<cnt2<<" "<<rem2<<endl;
		if(cnt2>0){
			if(rem4==0)return 0*printf("NO\n");
			else {
				req2+=cnt2;
			}
		}
	}
	if(req1>0){
		if(req1<rem2)req1=0;
		else req1-=rem2;
	}
	//if(rem4==0)return 0*printf("NO\n");
	int minm=min(req1,req2);
	if(rem4<minm)return 0*printf("NO\n");//cout<<"sdada"<<endl;
	rem4-=minm;req1-=minm;req2-=minm;
	if(req2>0){
		if(rem4<req2)return 0*printf("NO\n");
	}
	else if(req1>0){
		if(req1*2>rem4)return 0*printf("NO\n");
	}
	puts("YES");
}


