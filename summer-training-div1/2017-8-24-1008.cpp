#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
const int BUF=40000000;
char Buf[BUF],*buf=Buf;
const int OUT=20000000;
char Out[OUT],*ou=Out;int Outn[30],Outcnt;
inline void write(int x){
  if(!x)*ou++=48;
  else{
    for(Outcnt=0;x;x/=10)Outn[++Outcnt]=x%10+48;
    while(Outcnt)*ou++=Outn[Outcnt--];
  }
}
inline void writechar(char x){*ou++=x;}
inline void writeln(){*ou++='\n';}
inline void read(int&a){for(a=0;*buf<48;buf++);while(*buf>47)a=a*10+*buf++-48;}
struct{
	int e,next;
}ed[maxn<<1];
int head[maxn],num;
inline void add(int s,int e){
	ed[num].e=e;ed[num].next=head[s];head[s]=num++;
}
int ans=0,remn,remk;
int dfs(int u,int pre){
    int cnt=1;
    for(int i=head[u];i!=-1;i=ed[i].next){
        int e=ed[i].e;
        if(e==pre)continue;
        if(remk<=0)return 0;
        if(remk==1){
            ans++;
            remk=0;
            return 0;
        } 
        cnt+=dfs(e,u);
    }
    if(remk<=0)return 0;
    if(remk==1){
        ans++;
        remk=0;
        return 0;
    } 
    if(cnt==2){
        ans++;
        remn-=2;
        remk-=2;
        return 0;
    }
    else if(cnt>2){
        if(remn-cnt>=remk-2){
            ans++;
            remn-=cnt;
            remk-=2;
            return 0;
        }
        else {
            int res=remk-2-(remn-cnt);
            ans++;
            ans+=res;
            remn-=cnt;
            remk-=2+res;
            return 0;
        }
    }
    return cnt;
}
int main(){
	fread(Buf,1,BUF,stdin);
	int T;
	//scanf("%d",&T);
	read(T);
	while(T--){
		int n,k;
		//scanf("%d%d",&n,&k);
		read(n);read(k);
		ans=num=0;
		remn=n;remk=k;
		for(int i=1;i<=n;i++)head[i]=-1;
		for(int i=2;i<=n;i++){
			int x;
			read(x);
			//scanf("%d",&x);
			add(i,x);
			add(x,i);
		}
		dfs(1,-1);
		write(ans);writeln();
		//printf("%d\n",ans);
	}
	fwrite(Out,1,ou-Out,stdout);
}


