#include<bits/stdc++.h>
using namespace std;
int seq[1000010];
int main(){
    int n,s=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&seq[i]);
    if(n<3){
    	cout<<"-1"<<endl;
    	return 0;
    }
    int mx=max(seq[0],seq[1]);
    int sum=seq[0]+seq[1]-mx;
    for(int i=2;i<n;i++){
        if(seq[i]>mx)sum+=mx,mx=seq[i];
        else sum+=seq[i];
        if(sum>mx){
        	cout<<i+1<<endl;
        	return 0;
        }
    }
    cout<<"-1"<<endl;
}
