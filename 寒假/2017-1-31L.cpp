#include<bits/stdc++.h>
using namespace std;
int work(string s){
	if(s=="Alice"||s=="Phil"||s=="Phoebus")return 1;
	if(s=="Ariel"||s=="Peter"||s=="Ralph")return 1;
	if(s=="Aurora"||s=="Olaf"||s=="Robin")return 1;
	if(s=="Bambi"||s=="Mulan"||s=="Silver")return 2;
	if(s=="Belle"||s=="Mowgli"||s=="Simba")return 2;
	if(s=="Bolt"||s=="Mickey"||s=="Stitch")return 2;
	if(s=="Dumbo"||s=="Kuzko"||s=="Tarzan")return 3;
	if(s=="Genie"||s=="Kida"||s=="Tiana")return 3;
	if(s=="Jiminy"||s=="Kenai"||s=="Winnie")return 3;
}
int main(){
	int n,ans=0,now=1,pre=1;
	cin>>n;
	string s;
	while(n--){
		cin>>s;
		now=work(s);
		ans+=abs(now-pre);
		pre=now;
	}
	cout<<ans<<endl;
}


