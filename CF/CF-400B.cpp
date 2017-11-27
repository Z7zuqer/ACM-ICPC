#include<bits/stdc++.h>
using namespace std;
const int N = 100000+100;   
int prime[N] = {0},num_prime = 0;    
int isNotPrime[N] = {1, 1};   
void pre()   {     
     	for(int i = 2 ; i < N ; i ++)       
       	{            
		if(! isNotPrime[i])               
	 		prime[num_prime ++]=i;  
		//关键处1        
		for(int j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)
    		{               
		      	isNotPrime[i * prime[j]] = 1;  
	  		if( !(i % prime[j] ) )  //关键处2                  
				break;           
		}        
	}        
}  
int main(){
	int n;
	cin>>n;
	if(n==1){
		cout<<1<<endl;
		cout<<1<<endl;
		return 0;
	}
	if(n==2){
		cout<<1<<endl;
		cout<<"1 1"<<endl;
		return 0;
	}
	if(n==3){
		cout<<2<<endl;
		cout<<"1 1 2"<<endl;
		return 0;
	}
	pre();
	cout<<2<<endl;
	for(int i=2;i<=n+1;i++){
		if(isNotPrime[i])cout<<2<<" ";
		else cout<<1<<" ";
	}
}


