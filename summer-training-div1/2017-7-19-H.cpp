#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
char s[maxn][maxn];
int n;
#define POINT(x,y) make_pair(x,y)

template <class T>
inline void scand(T &res){
    res=0;
    int sgn=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sgn=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){res=res*10+(ch-'0');ch=getchar();}
    res *= sgn;
}
template <class T>
inline void outd(T x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)outd(x/10);
    putchar(x%10+'0');
}

struct node
{
    int i,j;
}tmp;
queue<node>q;
int di[]={-1,-1,-1,0,1,1,1,0};
int dj[]={-1,0,1,1,1,0,-1,-1};
int k[1005][1005];
char mapp[1005][1005];

void find_k()
{
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=n+1;j++)
        {
            k[i][j]=-2;
            if(i==0||i==n+1||j==0||j==n+1||s[i][j]=='#')
            {
                k[i][j]=-1;
                tmp.i=i;tmp.j=j;
                q.push(tmp);
            }
        }
    }
    while(!q.empty())
    {
        node st=q.front();
        node tar;
        q.pop();
        for(int i=0;i<8;i++)
        {
            tar=st;
            tar.i+=di[i];
            tar.j+=dj[i];
            if(tar.i<=0)continue;
            if(tar.i>=n+1)continue;
            if(tar.j<=0)continue;
            if(tar.j>=n+1)continue;
            if(s[tar.i][tar.j]=='#')continue;
            if(k[tar.i][tar.j]!=-2)continue;
            k[tar.i][tar.j]=k[st.i][st.j]+2;
            q.push(tar);
        }
    }
}


int vis[maxn][maxn];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int bfs(int kk,int stax,int stay,int endx,int endy){
	memset(vis,0,sizeof vis);
	queue<pair<int,int> >q;
	q.push(POINT(stax,stay));
	vis[stax][stay]=1;
	if(k[stax][stay]<kk)return 0;
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;q.pop();
		if(endx==x&&endy==y)return 1;
		for(int i=0;i<4;i++){
			int tx=x+dx[i];
			int ty=y+dy[i];
			if(tx>=1&&ty>=1&&tx<=n&&ty<=n&&!vis[tx][ty]&&k[tx][ty]>=kk&&s[tx][ty]!='#'){
				vis[tx][ty]=1;
				q.push(POINT(tx,ty));
			}
		}
	}
	return 0;
}
int main(){
	scand(n);
	for(int i=1;i<=n;i++){
		//gets(s[i]+1);
		scanf("%s",s[i]+1);
	}
	find_k();
	int q;
	scand(q);
	while(q--){
		int ra,ca,rb,cb;
		scand(ra);scand(ca);scand(rb);scand(cb);
		//scanf("%d%d%d%d",&ra,&ca,&rb,&cb);
		int l=0,r=(n+1)/2-1;
		if(!bfs(1,ra,ca,rb,cb)){
			putchar('0');
			putchar('\n');
			continue;
		}
		while(l<r){
			int mid=(l+r)>>1;
			if(bfs(mid*2+1,ra,ca,rb,cb))l=mid;
			else r=mid-1;
			//cout<<l<<" "<<r<<endl;
		}
		outd(l*2+1);
		putchar('\n');
		//printf("%d\n",l*2+1);
	}
}

