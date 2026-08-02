/*
    The 2025 Asia Yokohama Regional Contest - Problem G
*/

#include <bits/stdc++.h>
#include <cassert>
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
#define N 3000005
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define base 31
#define Kadoc 0

int n, m, k;
ll f[N], finv[N];

ll pw(ll a, ll b){
    if(b == 0) return 1;
    if(b == 1) return a % MOD;
    ll t = pw(a, b/2); t = t % MOD * t % MOD;
    if(b&1) return a % MOD * t % MOD;
    return t;
}

ll C(int k, int n){
    if(k < 0 || n <= 0 || k > n) return 0;
    if(k == 0 || k == n) return 1;
    if(k == 1 || k == n-1) return n;
    return f[n] * finv[k] % MOD * finv[n-k] % MOD;
}

ll F(int k, int n){
    return C(k+1, n+1);
}

void add(ll &a, ll b){
    a += b;
    if(a >= MOD) a -= MOD;
    if(a < 0) a += MOD;
}

void solve(){
    cin >> n >> k >> m;

    f[0] = 1;
    for(int i=1; i<=3000000; ++i) f[i] = f[i-1] * i % MOD;
    finv[3000000] = pw(f[3000000], MOD - 2);
    for(int i=3000000-1; i>=0; --i) finv[i] = finv[i+1] * (i+1) % MOD;

    ll Ans = 0;
    for(int r=1; r<=min(k, m); ++r){
        for(int len=0; len<n; ++len){
            if(r > 1 && 1ll * k - r - 1ll * len * (r - 1) < 0) break;
            int K = k - (len + 1) * r;

            ll cur = 0;
            add(cur, F(n - 2, K + n - 2 + len));
            add(cur, -F(n - 2, K + n - 3));
            cur = cur * C(len + 1, n) % MOD;

            if(len&1) add(Ans, -cur);
            else add(Ans, cur);
        }
    }

    ll Res = 0;
    for(int i=0; i<=n; ++i){
        if(k - 1ll * (m + 1) * i + n - 1 < 0) break;
        int K = k - (m + 1) * i;

        ll cur = C(n - 1, K + n - 1) * C(i, n) % MOD;
        if(i&1) add(Res, -cur);
        else add(Res, cur);
    }
    add(Res, -Ans);

    cout << Res;
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