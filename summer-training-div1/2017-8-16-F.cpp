#include<bits/stdc++.h>
using namespace std;
int t,k,w;
char s[1010];
bool vis[10000000];
int num[1000000];
int maxn,pos;
int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    for(int o=1;o<=t;o++){
        for(int i=1;i<=maxn;i++)vis[i]=0;
        maxn=0,pos=0;
        scanf("%d%d\n",&k,&w);
        for(int i=0;i<k;i++){
            int tmp_cnt=0;
            gets(s);
            int len=strlen(s);
            for(int l=0;l<len;l++){
                if(s[l]<='9'&&s[l]>='0'){
                    int r=l+1;
                    while(r<len&&s[r]>='0'&&s[r]<='9')r++;
                    for(int st=l;st<r;st++){
                        int tmp=0;
                        for(int tlen=1;tlen<=7;tlen++){
                            if(st+tlen-1>=r)break;
                            tmp*=10;
                            tmp+=s[st+tlen-1]-'0';
                            num[tmp_cnt++]=tmp;
                        }
                    }
                    l=r;
                }
            }
            sort(num,num+tmp_cnt);
            int j=0;
            while(num[j]<=pos+1&&j<tmp_cnt){
                if(num[j]<pos+1){
                    j++;
                    continue;
                }
                else{
                    pos++;
                    maxn=max(maxn,num[j]);
                    j++;
                    vis[pos]=1;
                    while(vis[pos+1])pos++;
                }
            }
            while(num[j]<=pos+w&&j<tmp_cnt){maxn=max(maxn,num[j]);vis[num[j]]=1;j++;}
        }
        printf("Case %d: %d %d\n",o,pos,maxn);
    }
    return 0;
}

