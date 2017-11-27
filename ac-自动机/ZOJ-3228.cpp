#include<bits/stdc++.h>
using namespace std;
const int MAXN=1011;
const int MaxSon=27;
int dp[MAXN][MAXN];
struct AC{
    int next[MAXN][MaxSon],Fail[MAXN],root,cnt,Len[MAXN];
    int idx(char c){
    	if(c=='A')return 0;
    	if(c=='G')return 1;
    	if(c=='C')return 2;
    	return 3;
    }
    int newnode(){
        for(int i=0;i<MaxSon;i++)next[cnt][i]=-1;
        Len[cnt]=Fail[cnt]=false;
        return cnt++;
    }
    void init(){
    	cnt=0;
        root=newnode();
    }
    int insert(char s[]){///返回这个字符串对应的节点编号
        int i,now=root;
        for(i=0;s[i];i++){
            int k=idx(s[i]);
            if(next[now][k]==-1)next[now][k]=newnode();
            now=next[now][k];
        }
        Len[now]=i;
        return now;
    }
    void GetFail(){
        queue<int>Q;
        int now = root;
        for(int i=0; i<MaxSon; i++){
            if(next[now][i] == -1)
                next[now][i] = root;
            else{
                Fail[next[now][i]] = root;
                Q.push(next[now][i]);
            }
        }
        while(Q.size()){
            now = Q.front();Q.pop();
            for(int i=0; i<MaxSon; i++){
                if(next[now][i] == -1)next[now][i] = next[Fail[now]][i];
                else{
                    Fail[next[now][i]] = next[Fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }
    void query(char MumStr[]){
        int now=root,temp;
        for(int i=0;MumStr[i];i++){
            int k=idx(MumStr[i]);
            now = next[now][k];
            cout<<now<<" "<<Len[now]<<endl;
            if(!now)continue;
            temp=now;
            while(temp!=root){
                if(Len[temp]);
                temp=Fail[temp];
            }
        }
    }
}ac;
char s[77],p[1010];
void solve(){
	for(int i=0;p[i];i++){
	//	[]
	}
}
int main(){
	int cas=1,n;
	while(scanf("%d",&n)==1&&n){
		ac.init();
		memset(dp,0x3f,sizeof dp);
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			ac.insert(s);
		}
		ac.GetFail();
		scanf("%s",p);
		printf("Case %d: ",cas++);
		ac.query(p);
	}
} 
