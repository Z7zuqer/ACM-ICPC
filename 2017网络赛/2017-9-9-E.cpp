#include<bits/stdc++.h>
using namespace std;
const int maxn = 20010;
stack<int> s;
vector<int> mp[maxn];
int dfn[maxn], low[maxn], colsiz[maxn], tclock, scccnt;
int res[maxn], od[maxn];
int T, n, m, x, y;
void tarjan(int u) {
	dfn[u] = low[u] = ++tclock;
	s.push(u);
	for (int i=0;i<mp[u].size();i++) {
		int v = mp[u][i];
		if (!dfn[v]) {				
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (!colsiz[v]) {		
			low[u] = min(low[u], dfn[v]);
		}
	}

	if (low[u] == dfn[u]) {
		scccnt++;
		int v = -1;
		while (v != u) {
			v = s.top();
			s.pop();
			colsiz[v] = scccnt;
		}
	}
}

int work() {
	if(scccnt == 1)return 0;
	memset(res, 0, sizeof(res));
	memset(od, 0, sizeof(od));
	for (int u=1;u<=n;u++) {
		int sz = mp[u].size();
		for (int i=0;i<=sz - 1;i++) {
			int v = mp[u][i];
			if (colsiz[u] != colsiz[v]) {
				res[colsiz[v]]++;
				od[colsiz[u]]++;
			}
		}
	}

	int idnum = 0, odnum = 0;
	for(int i=1;i<=scccnt;i++) {
		idnum += (res[i] == 0);
		odnum += (od[i] == 0);
	}

	return max(idnum, odnum);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i=0;i<=n;i++)mp[i].clear();
		for(int i=1;i<=m;i++){
			scanf("%d%d", &x, &y);
			mp[x].push_back(y);
		}
		tclock = scccnt = 0;
	    memset(dfn, 0, sizeof(dfn));
	    memset(low, 0, sizeof(low));
	    memset(colsiz, 0, sizeof(colsiz));
	    for (int i=1;i<=n;i++)
		    if (!dfn[i]) 
			   tarjan(i);
		printf("%d\n", work());
	}
}

