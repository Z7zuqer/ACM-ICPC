#include<bits/stdc++.h>
using namespace std;
#define LL long long
const double eps = 1e-12;
double num[7]; 
int cmp(double x){
	if(fabs(x)<eps)return 0;
	return x > 0 ? 1 : -1;
}
int main(){
 	while(cin>>num[0]>>num[1]>>num[2]&&fabs(num[0])!=0&&fabs(num[1])!=0&&fabs(num[2])!=0){
 		sort(num,num+3);
 		double mi=num[0];
 		LL h=floor(num[1]+0.5),l=floor(num[2]+0.5);
 		int flg=0;
 		if(cmp(mi-0.25)>=0&&h>=90&&l>=125){
 			if(cmp(7-mi)>=0&&h<=155&&l<=290){
 				cout<<"letter"<<endl;
 				flg=1;
 			}
 			else {
 				if(cmp(50-mi)>=0&&h<=300&&l<=380){
 					cout<<"packet"<<endl;
 					flg=1;
 				}
 				else if(cmp(mi*2+(double)h*2+(double)l-2100)<=0){
 					cout<<"parcel"<<endl;
 					flg=1;
 				}
 			}
 		}
 		if(!flg)cout<<"not mailable"<<endl;
 	}
}
