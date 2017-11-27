#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=100100;
int sz[maxn],son[maxn],dep[maxn],fa[maxn],in[maxn],top[maxn],tot;
vector<vector<int> > G(maxn);
int rt[maxn],cur=0,num=0;
struct {
	int l,r;
	LL sum;
}tr[maxn*20];
void pushup(int t){
	tr[t].sum=tr[tr[t].l].sum+tr[tr[t].r].sum;
}
int build(int l,int r){
	int k=num++;
	if(l==r){
		tr[k].sum=0;
		return k;
	}
	int mid=(l+r)>>1;
	tr[k].l=build(l,mid);
	tr[k].r=build(mid+1,r);
	pushup(k);
	return k;
}
int update(int o,int l,int r,int pos ,LL val){
    int k = cur++;
    tr[k] = tr[o];
    if(l == r){
        tr[k].sum += val;
        return k;
    }
    int mid = (l+r)/2;
    if(pos <= mid) tr[k].l = update(tr[o].l,l,mid,pos,val);
    else tr[k].r = update(tr[o].r,mid+1,r,pos,val);
    pushup(k);
    return k;
}
LL query(int l,int r,int ox,int oy,int L,int R){
    if(L <= l && r <= R)return tr[oy].sum - tr[ox].sum;
    int mid = (l+r)/2;
	LL res = 0;
    if(L <= mid) res += query(l,mid,tr[ox].l,tr[oy].l,L,R);
    if(R > mid) res += query(mid+1,r,tr[ox].r,tr[oy].r,L,R);
    return res;
}
int n,m,A[maxn],B[maxn],D[maxn];
int find(int x){
	int l=1,r=n+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(B[mid]>=x)r=mid;
		else l=mid+1;
	}
	return r;
}
void dfs1(int v,int pre,int d){
    dep[v] = d;
    fa[v] = pre;
    sz[v] = 1;
    for(int i=0;i<G[v].size();i++){
    	int x=G[v][i];
        if(x == pre) continue;
        dfs1(x,v,d+1);
        sz[v] += sz[x];
        if(son[v] == 0 || sz[son[v]] <sz[x]) son[v] = x;
    }
}
void dfs2(int v,int t){
    top[v] = t;
    in[v] = ++tot;
    //cout<<v<<" "<<in[v]<<" "<<D[v]<<" "<<A[v]<<endl;
    rt[in[v]]=update(rt[in[v]-1],1,n,D[v],A[v]);
    if(!son[v]) return;
    dfs2(son[v],t);
    for(int i=0;i<G[v].size();i++){
    	int x=G[v][i];
        if(x != fa[v] && x != son[v]) dfs2(x,x);
	}
}
LL tcQuerySum(int s,int t,int a,int b){
    LL res = 0;
    int f1 = top[s], f2 = top[t];
    while(f1 != f2){
        if(dep[f1] < dep[f2]) swap(f1,f2), swap(s,t);
        res += query(1,n,rt[in[f1]-1],rt[in[s]],a,b);
        //cout<<in[f1]-1<<" "<<in[s]<<endl;
        s = fa[f1];
        f1 = top[s];
    }
    if(dep[s] > dep[t]) swap(s,t);
    //cout<<s<<" "<<t<<endl;
    res += query(1,n,rt[in[s]-1],rt[in[t]],a,b);
    return res;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		num=cur=tot=0;
		memset(sz,0,sizeof 0);
        memset(son,0,sizeof 0);
        memset(dep,0,sizeof 0);
        memset(fa,0,sizeof 0);
        memset(in,0,sizeof 0);
        memset(top,0,sizeof 0);
		for(int i=1;i<=n;i++)scanf("%d",&A[i]),B[i]=A[i];
		sort(B+1,B+n+1);
		for(int i=1;i<=n;i++)D[i]=find(A[i]);
		for(int i=1;i<=n;i++)G[i].clear();
		rt[0]=build(1,n);
		for(int i=1;i<=n-1;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		dfs1(1,1,0);
		dfs2(1,1);
		//for(int i=1;i<=n;i++)printf("%d\n",query(1,n,rt[in[i]-1],rt[in[i]],1,7));
		//for(int i=1;i<=n;i++)rt[i]=update(rt[i-1],1,n,in[D[i]],A[i]);
		cout<<query(1,n,rt[0],rt[3],1,3)<<endl;
		for(int i=1;i<=m;i++){
			int s,t,a,b;
			scanf("%d%d%d%d",&s,&t,&a,&b);
			int posa=find(a),posb=find(b); 
			if(i!=m)printf("%lld ",tcQuerySum(s,t,posa,posb));
			else printf("%lld\n",tcQuerySum(s,t,posa,posb));
		}
	}
}

