#include<bits/stdc++.h>
using namespace std;
char s1[23],s2[23]; 
int trans(char ch){
    if(ch=='T')return 10;
    if(ch=='J')return 11;
    if(ch=='Q')return 12;
    if(ch=='K')return 13;
    if(ch=='A')return 14;
    if(ch>='3'&&ch<='9')return ch-'0';
    return 15;
}
int main(){
    scanf("%s%s",s1+1,s2+1);
    int len1=strlen(s1+1),len2=strlen(s2+1);
    if(len1==1||(trans(s1[len1])>=trans(s2[len2]))){
    	cout<<"zhong_wang"<<endl;
    	return 0;
    }
    int k=trans(s1[len1]),cnt=0;
    for(int i=1;i<=len2;i++)
    	if(trans(s2[i])<k)cnt++;
    if(cnt>=2){
    	cout<<"zhong_wang"<<endl;
    	return 0;
    }
	cout<<"cfeitong"<<endl;
}
