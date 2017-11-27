#include<bits/stdc++.h>
using namespace std;
int get(){
	return rand()%1000000000;
}
int main(){
	int n=80;
	freopen("C://Users//Duhao//Desktop//in.txt","w",stdout);
	cout<<80<<" "<<get()<<endl;
	for(int i=1;i<=n;i++)cout<<get()<<" "<<get()<<endl;
}


