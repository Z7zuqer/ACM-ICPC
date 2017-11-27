#include<bits/stdc++.h>
using namespace std;
char s[1001000];
int main(){
    int k;
    scanf("%d",&k);
    int cnt=0;
    if(k==0)return 0*printf("a\n");
    char c='a';
    while(k>0){
        int res=0,sum=0,tmp=0;
        while(k>=sum){
            tmp=sum;
            res++;
            sum+=res;
        }
        k-=tmp;
        for(int i=1;i<=res;i++)s[++cnt]=c;
        if(k<=0)break;
        c++;
    }
    for(int i=1;i<=cnt;i++)printf("%c",s[i]);
}

