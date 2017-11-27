#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=1e7;   
int prime[maxn]={0},num_prime;    
int isNotPrime[maxn]={1,1};   
void pre(){     
    for(int i=2;i<maxn;i++){
    	if(!isNotPrime[i])prime[num_prime++]=i;
    	for(int j=0;j<num_prime&&i*prime[j]<maxn;j++){
    		isNotPrime[i*prime[j]]=1;
    		if(!(i%prime[j]))break;
    	}
    }
}  
int main(){
	LL n;
	cin>>n;
	pre();
	int cnt=0;
	for(int i=0;i<num_prime&&prime[i]*prime[i]<=n;i++){
		while(n%prime[i]==0){
			cnt++;
			n/=prime[i];
			if(cnt>20)break;
		}
		if(cnt>20)break;
	}
	if(n!=1)cnt++;
	if(cnt<20||cnt>20)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}


