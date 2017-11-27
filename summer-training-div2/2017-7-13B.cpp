#include<bits/stdc++.h>
using namespace std;
const int L=110;
string add(string a,string b)//只限两个非负整数相加
{
    string ans;
    int na[L]={0},nb[L]={0};
    int la=a.size(),lb=b.size();
    for(int i=0;i<la;i++) na[la-1-i]=a[i]-'0';
    for(int i=0;i<lb;i++) nb[lb-1-i]=b[i]-'0';
    int lmax=la>lb?la:lb;
    for(int i=0;i<lmax;i++) na[i]+=nb[i],na[i+1]+=na[i]/10,na[i]%=10;
    if(na[lmax]) lmax++;
    for(int i=lmax-1;i>=0;i--) ans+=na[i]+'0';
    return ans;
}
int main()
{
    string a,b,c;
    while(cin>>a>>b>>c){
    	if(add(a,b)==c||add(a,c)==b||add(b,c)==a)puts("YES");
    	else if(add(a,a)==b||add(a,a)==c||add(b,b)==a)puts("YES");
    	else if(add(c,c)==a||add(c,c)==b||add(b,b)==c)puts("YES");
    	else puts("NO");
    	//if(add(a,b)==c||add(a,c)==b||add(b,c)==a)puts("YES");
    }
    return 0;
}
