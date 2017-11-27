#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
	for(int i=1;i<=10;i++)v.push_back(i);
	for(auto &x:v)x*=x;
	for(auto x:v)cout<<x<<endl;
}
