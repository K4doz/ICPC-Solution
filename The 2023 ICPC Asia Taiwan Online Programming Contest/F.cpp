#include<bits/stdc++.h>
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FORD(i, l, r) for (int i = l; i >= r; i--)
#define ll long long 
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
using namespace std;

int n, m, q;
bool isQuery[N];
int Ans[N];

struct Edge{
    int u, v, id;

    Edge() = default;
    Edge(int _u, int _v, int _id){
        u = _u;
        v = _v;
        id = _id;
    }

    bool operator < (Edge &b){
        return pii(u, v) < pii(b.u, b.v);
    }
} add[N], del[N];

bool cmp(Edge &a, Edge &b){
    return a.id < b.id;
}

struct DSU{
    int n;
    vector<int> par, sz;

    DSU() = default;
    DSU(int _n){
        n = _n;
        par.resize(n + 5);
        sz.resize(n + 5, 1);
        for(int i=1; i<=n; ++i){
            par[i] = i;
        }
    }

    int get(int u){
        return par[u] = (u == par[u]? u:get(par[u]));
    }

    int join(int u, int v){
        u = get(u), v = get(v);
        if(u == v) return 0;
        if(sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return 1;
    }
};

/////////////////////////////////////////////////////////////

// Segxi

int st[N << 2], lz[N << 2];

void push(int id, int l, int r){
    if(lz[id] < 0) return;

    st[id] = (r - l + 1) * lz[id];
    if(l != r){
        lz[id<<1] = lz[id];
        lz[id<<1|1] = lz[id];
    }

    lz[id] = -1;
}

void upd(int id, int l, int r, int u, int v, int x){
    push(id, l, r);
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        lz[id] = x;
        push(id, l, r);
        return;
    }

    int m = (l+r)>>1;
    upd(id<<1, l, m, u, v, x);
    upd(id<<1|1, m+1, r, u, v, x);
    st[id] = st[id<<1] + st[id<<1|1];
}

int get(int id, int l, int r, int u, int v){
    push(id, l, r);
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int m = (l+r)>>1;
    return get(id<<1, l, m, u, v) + get(id<<1|1, m+1, r, u, v);
}

///////////////////////////////////////////////////////////////////////////////////

// Tarjan
vector<int> V;
int id[N], nComp;
vector<int> Q[N], g[N];
int low[N], num[N], cnt = 0;

void tarjan(int u, int p = -1){
    V.push_back(u);
    low[u] = num[u] = ++cnt;

    for(int v : g[u]) if(v != p){
        if(num[v] == 0){
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }

    if(low[u] == num[u]){
        ++nComp;
        int v = V.back();
        do{
            v = V.back();
            V.pop_back();
            id[v] = nComp;
            Q[nComp].push_back(v);
        }
        while(u != v);
    }
}

//////////////////////////////////////////////////////////

// HLD
int pos[N], sz[N], par[N], h[N], head[N], w[N], Timer = 0;
vector<pii> G[N];

void dfs_sz(int u, int p = -1){
    sz[u] = 1;
    for(auto [v, l]:G[u]) if(v != p){
        par[v] = u;
        w[v] = l;
        h[v] = h[u] + 1;
        dfs_sz(v, u);
        sz[u] += sz[v];
    }
}

void hld(int u, int p){
    head[u] = p;
    pos[u] = ++Timer;

    int bigC = -1;
    for(auto [v, w]:G[u]) if(v != par[u] && v != bigC && (bigC < 0 || sz[v] > sz[bigC])) bigC = v;
    
    if(bigC != -1) hld(bigC, p);
    for(auto [v, l]:G[u]) if(v != par[u] && v != bigC) hld(v, v);
}

void updPath(int u, int v, int x){
    for(;head[u] != head[v]; u = par[head[u]]){
        if(h[head[u]] < h[head[v]]) swap(u, v);
        upd(1, 1, nComp, pos[head[u]], pos[u], x);
    }

    if(h[u] > h[v]) swap(u, v);
    upd(1, 1, nComp, pos[u] + 1, pos[v], x);
}

///////////////////////////////////////////////////////////////////////

// Solution

void Solve() {
    cin >> n >> m >> q;
    for(int i=1; i<=m; ++i){
        int u, v; cin >> u >> v;
        if(u > v) swap(u, v);
        add[i] = Edge(u, v, i);
    }

    for(int i=1; i<=q; ++i){
        int u, v; cin >> u >> v;
        if(u > v) swap(u, v);
        del[i] = Edge(u, v, i);
    }

    sort(add+1, add+m+1);
    sort(del+1, del+q+1);

    vector<Edge> remain;

    for(int i=1, j=1; i<=m; ++i){
        if(j <= q && pii(add[i].u, add[i].v) == pii(del[j].u, del[j].v)){
            j++;
            continue;
        }

        remain.pb({add[i].u, add[i].v, -1});
    }

    for(Edge p:remain){
        int u = p.u, v = p.v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i=1; i<=n; ++i) if(!num[i]){
        tarjan(i);
    }

    DSU T(nComp);
    for(Edge p:remain){
        int u = id[p.u], v = id[p.v];
        if(u != v){
            G[u].pb({v, 1});
            G[v].pb({u, 1});
            T.join(u, v);
        }
    }

    sort(del+1, del+q+1, cmp);
    for(int i=q; i>=1; --i){
        int u = id[del[i].u], v = id[del[i].v];
        if(T.get(u) != T.get(v)){
            G[u].pb({v, 0});
            G[v].pb({u, 0});
            T.join(u, v);
        }
        else{
            isQuery[i] = 1;
        }
    }
    for(int i=1; i<=nComp; ++i) if(!pos[i]){
        dfs_sz(i);
        hld(i, i);
    }

    memset(lz, -1, sizeof lz);

    for(int i=1; i<=nComp; ++i) upd(1, 1, nComp, pos[i], pos[i], w[i]);

    for(int i=q; i>=1; --i){
        int u = id[del[i].u], v = id[del[i].v];
        
        Ans[i] = st[1];
        if(!isQuery[i]){
            if(h[u] < h[v]) swap(u, v);
            upd(1, 1, nComp, pos[u], pos[u], 1);
        }
        else{
            updPath(u, v, 0);
        }
    }
    
    for(int i=1; i<=q; ++i) cout << Ans[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen("task.inp", "r")){
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }

    int T = 1;
    while(T--){
        Solve();
    }
}
