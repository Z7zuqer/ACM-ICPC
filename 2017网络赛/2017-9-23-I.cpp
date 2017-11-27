#include<bits/stdc++.h>
using namespace std;

typedef long long SgTreeDataType;
struct treenode{
    int L , R  ;
    SgTreeDataType mx, lazy, mn;
    void update(SgTreeDataType v){
        mx += v;
        mn += v;
        lazy += v;
    }
};

treenode tree[4 * 150010];

inline void push_down(int o){
    SgTreeDataType & lazyval = tree[o].lazy;
    tree[2*o].update(lazyval) ; tree[2*o+1].update(lazyval);
    lazyval = 0;
}

inline void push_up(int o){
    tree[o].mx = max(tree[2*o].mx,tree[2*o+1].mx);
    tree[o].mn = min(tree[2*o].mn,tree[2*o+1].mn);
}

inline void build_tree(int L, int R, int o){
    tree[o].L = L, tree[o].R = R, tree[o].mx = tree[o].mn = tree[o].lazy = 0;
    if (R > L){
        int mid = (L+R) >> 1;
        build_tree(L,mid,o*2);
        build_tree(mid+1,R,o*2+1);
    }
}

inline void update(int QL,int QR,SgTreeDataType v,int o){
    int L = tree[o].L , R = tree[o].R;
    if (QL <= L && R <= QR) tree[o].update(v);
    else{
        push_down(o);
        int mid = (L+R)>>1;
        if (QL <= mid) update(QL,QR,v,o*2);
        if (QR >  mid) update(QL,QR,v,o*2+1);
        push_up(o);
    }
}

inline SgTreeDataType queryMax(int QL,int QR,int o){
    int L = tree[o].L , R = tree[o].R;
    if (QL <= L && R <= QR) return tree[o].mx;
    else{
        push_down(o);
        int mid = (L+R)>>1;
        SgTreeDataType res = -1e18;
        if(QL <= mid)
            res = queryMax(QL,QR,2*o);
        if(QR > mid)
            res = max(res,queryMax(QL,QR,2*o+1));
        return res;
    }
}

inline SgTreeDataType queryMin(int QL,int QR,int o){
    int L = tree[o].L , R = tree[o].R;
    if (QL <= L && R <= QR) return tree[o].mn;
    else{
        push_down(o);
        int mid = (L+R)>>1;
        SgTreeDataType res = 1e18;
        if(QL <= mid)
            res = queryMin(QL,QR,2*o);
        if(QR > mid)
            res = min(res,queryMax(QL,QR,2*o+1));
        return res;
    }
}

int T,k,q,powof2[22] = {1};

int main(){
    for(int i = 1;i <= 17;++i) powof2[i] = powof2[i-1] * 2;
    cin >> T;
    while(T--){
        scanf("%d",&k);
        int n = powof2[k];
        build_tree(1,n,1);
        for(int i = 1;i <= n;++i){
            int a;
            scanf("%d",&a);
            update(i,i,a,1);
        }
        scanf("%d",&q);
        while(q--){
            int op,l,r;
            scanf("%d%d%d",&op,&l,&r);
            if(op == 1){
                long long mx = queryMax(l+1,r+1,1);
                long long mn = queryMin(l+1,r+1,1);
                if(mx <= 0) printf("%lld\n",mx*mx);
                else if(mn >= 0) printf("%lld\n",mn*mn);
                else printf("%lld\n",mx*mn);
            }
            else
                update(l+1,l+1,1LL*r-queryMax(l+1,l+1,1),1);
        }
    }

    return 0;
}

