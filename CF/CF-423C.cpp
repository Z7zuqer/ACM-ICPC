#include <bits/stdc++.h>
using namespace std;
const int maxn=3000010;
int n,maxm,fa[maxn],rk[maxn];
char s[maxn],r[maxn];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void uni(int x,int y){
    int fx=find(x);
	int fy=find(y);
    if(fx>fy)fa[fx]=fy;
    else fa[fy]=fx;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<maxn;i++)fa[i]=i,rk[i]=i;
    for(int i=1;i<=n;i++){
    	int m;
        scanf("%s%d",s+1,&m);
        int len=strlen(s+1);
        while(m--){
            int x;scanf("%d",&x);
            int lennow=1;maxm=max(x+len-1,maxm);
            while(lennow<=len){
                int end=find(x);
                lennow+=rk[end]-x;
                x=rk[end];
                while(lennow<=len){
                	if(r[x])break;
                    if(r[x-1]==0)rk[x]=x+1;
                    else{
                    	uni(x-1,x);
                    	int sta=find(x-1);
						rk[sta]=x+1;
                    }
                    r[x++]=s[lennow++];
                }
            }
        }
    }
    for(int i=1;i<=maxm;i++)
    	if(r[i]==0)printf("a");
    	else printf("%c",r[i]);
    cout<<endl;
}


