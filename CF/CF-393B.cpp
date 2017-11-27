#include<bits/stdc++.h>
using namespace std;
#define LL long long
int A[300010],B[300010];
char s[50];
int a,b,c,k,m;
int n1,n2,n3;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d%s",&k,s);
		if(s[0]=='U')A[n1++]=k;
		if(s[0]=='P')B[n2++]=k;
	}
	sort(A,A+n1);
	sort(B,B+n2);
	LL ans=0;
	int wh1=0,wh2=0;
	int r1=0,r2=0,r3=0;
	for(int i=0;i<n1&&i<a;i++){
		ans+=A[i];
		wh1=i+1;
		r1++;
	}
	for(int i=0;i<n2&&i<b;i++){
		ans+=B[i];
		wh2=i+1;
		r2++;
	}
	//cout<<r1+r2<<endl;
	while(c&&(wh1<n1||wh2<n2)){
		int minv=1e9+10,flg=0;
		if(wh1<n1){
			minv=A[wh1];
			flg=1;
		}
		if(wh2<n2){
			if(minv>B[wh2]){
				minv=B[wh2];
				flg=2;
			}
		}
		ans+=minv;r3++;c--;
		if(flg==1)wh1++;
		if(flg==2)wh2++;
	}
	cout<<r1+r2+r3<<" "<<ans<<endl;
}


