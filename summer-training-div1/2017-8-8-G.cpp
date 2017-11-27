#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n,k,cnt;
int num[200005];
struct node
{
    int id;
    long long val;
    friend bool operator < (const node &a,const node &b)
    {
        return a.val>b.val;
    }
};
priority_queue<node>q;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    sort(num,num+n);
    node st;
    st.id=0;st.val=num[0];
    q.push(st);
    while(!q.empty())
    {
        st=q.top();
        q.pop();
        cnt++;
        if(cnt==k)break;
        if(st.id==n-1)continue;
        node nt=st;
        nt.id++;nt.val+=num[nt.id];
        q.push(nt);
        nt.val-=num[nt.id-1];
        q.push(nt);
    }
    cout<<st.val;
    return 0;
}
