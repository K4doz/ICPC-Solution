/*
    Author: Cadocx
    Codeforces: https://codeforces.com/profile/Kadoc
    VNOJ: oj.vnoi.info/user/Cadoc
*/

#include <bits/stdc++.h>
using namespace std;

// input/output
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define el cout << '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s"
// #pragma GCC optimize("O2", "unroll-loops", "Ofast")
// #pragma GCC target("avx,avx2,fma")
//data type
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define piv pair<int, vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define vc vector<char>
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return 1; }; return 0; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return 1; }; return 0; }
//STL
#define sz(x) (int)(x).size()
#define FOR(i,l,r) for(auto i = l; i <= r; i++)
#define FORD(i,r,l) for(auto i = r; i >= l; i--)
#define forin(i,a) for(auto i : a)
#define pb push_back
#define eb emplace_back
#define pf push_front
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
//bitmask
#define bitcnt(n) __builtin_popcount(n)
#define MASK(i) (1 << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define set_on(n, i) ((n) | mask(i))
#define set_off(n, i) ((n) & ~mask(i))
//constant
#define N 200005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define base 31
#define Kadoc 0

int n, m, s, t, velo;
vector<pii> g[N];
ll d[N];

struct Node{
    ll du; int u;

    Node() = default;
    Node(ll _du, int _u){
        du = _du;
        u = _u;
    }

    bool operator < (const Node &b) const{
        return b.du < du;
    }
};

void solve(){
    cin >> n >> m >> velo;
    FOR(i, 1, m){
        int u, v, w; cin >> u >> v >> w;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }

    cin >> s >> t;
    priority_queue<Node> q;
    memset(d, 0x3f, sizeof d);
    d[s] = 0;
    q.emplace(0, s);

    while(q.size()){
        auto [du, u] = q.top(); q.pop();
        if(du != d[u]) continue;

        if(u == t){
            cout << fixed << setprecision(6) << (double)((d[t] - 1ll * velo * max(0, (sz(g[t]) - 2)))) / velo;
            return;
        }

        for(auto [v, w]:g[u]){
            if(minimize(d[v], d[u] + w + 1ll * velo * max(0, (sz(g[v]) - 2)))){
                q.emplace(d[v], v);
            }
        }
    }
}

int main(){
    #define NAME "TASK"
    if(fopen(NAME".inp", "r")){
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }

    fastIO;
    
    if(Kadoc){
        int tc; cin >> tc;
        while(tc--){
            solve();
        }
    } else solve();
}
