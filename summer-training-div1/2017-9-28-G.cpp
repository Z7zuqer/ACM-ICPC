#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
double res[10]={10,100,999.96,5320.04,8735.71,9756.92,9994.96};
int main(){
	//srand(time(0));
	string r;
	for(int i=1;i<=10;i++){
		puts("+");
		fflush(stdout);
		cin>>r;
		mp[r]=1;
	}
	int siz=mp.size(),ans;
	double minv=1e18;
	for(int i=0;i<7;i++){
		if(fabs(res[i]-1.0*siz)<minv){
			minv=fabs(res[i]-1.0*siz);
			ans=i;
		}
	}
	ans=pow(10,ans+1);
	cout<<"= "<<ans<<endl;
	fflush(stdout);
}


