#include<bits/stdc++.h>
using namespace std;
int A[110];
int main(){
	 int T;
	 cin>>T;
	 while(T--){
	 	int n;
	 	scanf("%d",&n);
	 	int maxv=-1001,minv=1001,cnt=0;
		for(int i=1;i<=n;i++){
	 		scanf("%d",&A[i]);
	 		maxv=max(maxv,A[i]);
	 		if(minv>A[i])minv=A[i],cnt=1;
	 		else if(minv==A[i])cnt++;
	 	}
	 	if(minv!=1){
	 		cout<<"No"<<endl;
	 		continue;
	 	}
	 	if(cnt<2||(n<10||n>13)){
	 		cout<<"No"<<endl;
	 		continue;
	 	}
	 	int flg=0;
	 	sort(A+1,A+1+n);
	 	for(int i=1;i<n;i++){
	 		if(A[i]==maxv||A[i+1]==maxv);
	 		else if(A[i+1]-A[i]<=2);
	 		else {
	 			flg=1;
	 			break;
	 		}
	 	}
	 	if(flg)cout<<"No"<<endl;
	 	else cout<<"Yes"<<endl;
	 } 
}


