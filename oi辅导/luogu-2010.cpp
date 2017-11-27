#include<bits/stdc++.h>
using namespace std;
int month1[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int month2[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int check(int year){
	int r[5],tmp=year;
	for(int i=4;i>=1;i--)r[i]=tmp%10,tmp/=10;
	int month=r[1]*10+r[2],day=r[3]*10+r[4];
	if(month<1||month>12)return 0;
	cout<<month<<" "<<day<<endl;
	int flg=(year%4==0)&&(year%100!=0);flg|=(year%400==0);
	if(flg)return day>=1&&day<=month2[month];
	else return day>=1&&day<=month1[month];
}
int main(){
	int sta,end,ans=0;
	scanf("%d%d",&sta,&end);
	int stayear=sta/10000,endyear=end/10000;
	for(int i=stayear+1;i<endyear;i++)
		if(check(i))
			ans++;
	if(check(stayear)){
		int r[5],tmp=stayear,power=1;for(int i=4;i>=1;i--)r[i]=tmp%10,tmp/=10;
		int checkyear=stayear/10000*10000;
		for(int i=4;i>=1;i--)checkyear+=power*r[i];
		
		if(checkyear>=sta)ans++;
	}
	if(check(endyear)&&stayear!=endyear){
		int r[5],tmp=endyear,power=1;for(int i=4;i>=1;i--)r[i]=tmp%10,tmp/=10;
		int checkyear=endyear/10000*10000;
		for(int i=4;i>=1;i--)checkyear+=power*r[i];
		if(checkyear<=end)ans++;
	}
	printf("%d\n",ans);
}


