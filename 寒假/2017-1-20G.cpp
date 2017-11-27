#include<bits/stdc++.h>
using namespace std;
const int maxn=2001001;
char s[maxn+100];
int fail[maxn+100];
int getfail(char s[]){
    int l=strlen(s);
    fail[0]=fail[1]=0;
    for(int i=1;i<=l;++i){
        int j=fail[i];
        while(j&&s[i]!=s[j])j=fail[j];
        fail[i+1]=s[i]==s[j]?j+1:0;
    }
    if(l%(l-fail[l])==0)return l-fail[l];
    return l;
}
struct SAM{
    int next[107+maxn<<1][26],len[107+maxn<<1],link[107+maxn<<1],last,cnt,rankk[107+maxn<<1],v[maxn+100],num[107+maxn<<1],l,minlen[107+maxn<<1];
    void init(){
        memset(next[1],0,sizeof(next[1]));
        memset(v,0,sizeof(v));
        minlen[1]=num[1]=len[last=cnt=1]=link[1]=0;
    }
    int newnode(){
        memset(next[++cnt],0,sizeof(next[cnt]));
        num[cnt]=len[cnt]=link[cnt]=minlen[cnt]=0;
        return cnt;
    }
    void add(int c){
        int p=last,cur=last=newnode();
        len[cur]=len[p]+1;
        num[cur]=1;
        for(;p&&!next[p][c];p=link[p])next[p][c]=cur;
        if(!p)link[cur]=minlen[cur]=1;
        else{
            int q=next[p][c];
            if(len[q]==len[p]+1)link[cur]=q,minlen[cur]=len[q]+1;
            else{
                int np=newnode();
                len[np]=len[p]+1;
                link[np]=link[q];
                minlen[np]=minlen[q];
                memcpy(next[np],next[q],sizeof(next[p]));
                link[q]=link[cur]=np;
                minlen[q]=minlen[cur]=len[np]+1;
                for(;p&&next[p][c]==q;p=link[p])next[p][c]=np;
            }
        }
    }
    void insert(char s[]){
        l=strlen(s);
        for(int i=0;i<l;++i)add(s[i]-'a');
    }
    void pre(){
	    for(int i=1;i<=cnt;++i)v[len[i]]++;
        for(int i=1;i<=l;++i)v[i]+=v[i-1];
        for(int i=1;i<=cnt;++i)rankk[v[len[i]]--]=i;
        for(int i=cnt;i;--i)num[link[rankk[i]]]+=num[rankk[i]];
    }
}sam;
int main(){
    scanf("%s",s);
    sam.init();
    sam.insert(s);
    sam.pre();
    int q;
    scanf("%d",&q);
    while(q--){
        int num=0,ans=0;
        scanf("%s",s);
        int l=strlen(s);
        int len=l;
        int e=getfail(s);
        for(int i=0;i<e-1;++i)
            s[len++]=s[i];
        s[len]='\0';
        int cur=1;
        for(int i=0;i<len;++i){
            int c=s[i]-'a';
            while(cur&&!sam.next[cur][c]){
                cur=sam.link[cur];
                num=sam.len[cur];
            }
            if(!cur)num=0,cur=1;
            else{
                num++;
                cur=sam.next[cur][c];
                if(num<l)continue;
                int p=cur;
                while(sam.minlen[p]>l)
                    p=sam.link[p];
                if(sam.len[p]>=l)
                    ans+=sam.num[p];
            }
        }
    	printf("%d\n",ans);
    }
}
