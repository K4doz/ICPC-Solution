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
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define base 31
#define Kadoc 0

int n, q;

inline void add(int &a, int b){
    a += b;
    if(a >= MOD) a -= MOD;
    if(a < 0) a += MOD;
}

inline int sqr(int &x){
    return 1ll * x * x % MOD;
}

inline int mul(int a, int b){
    return 1ll * a * b % MOD;
}

inline int pw(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    int t = pw(a, b/2); t = mul(t, t);
    if(b&1) return mul(a, t);
    return t;
}

struct Matrix{
    int val[3][3];
    int n, m;

    int row(){
        return n;
    }

    int col(){
        return m;
    }

    Matrix(){
        memset(val, 0, sizeof val);
    }
    Matrix(int r, int c){
        n = r;
        m = c;
        memset(val, 0, sizeof val);
    }
    static Matrix identity(int n){
        Matrix a(n, n);
        FOR(i, 0, n-1) a.val[i][i] = 1;
        return a;
    }

    Matrix operator * (Matrix b){
        Matrix a = *this;
        int m = a.row(), n = a.col(), p = b.col();
        Matrix c(m, p);
        FOR(i, 0, m-1) FOR(j, 0, p-1) FOR(k, 0, n-1){
            add(c.val[i][j], mul(a.val[i][k], b.val[k][j]));
        }
        return c;
    }
} st[N << 2];

inline void MakeGoldMatrix(Matrix &T, int a, int b, int c, int inv){
    T = Matrix(3, 3);
    T.val[0][0] = mul(sqr(b), inv);
    T.val[0][1] = MOD - mul(mul(a, b), inv);
    T.val[0][2] = MOD - mul(mul(a, c), inv);
    T.val[1][0] = MOD - mul(mul(a, b), inv);
    T.val[1][1] = mul(sqr(a), inv);
    T.val[1][2] = MOD - mul(mul(b, c), inv);
    T.val[2][2] = 1;
}

inline void MakeDiaMatrix(Matrix &T, int a, int b, int c, int inv){
    T = Matrix(3, 3);
    int A = sqr(b), B = sqr(a);
    add(A, -sqr(a)); add(B, -sqr(b));
    T.val[0][0] = mul(A, inv);
    T.val[0][1] = MOD - mul(2, mul(mul(a, b), inv));
    T.val[0][2] = MOD - mul(2, mul(mul(a, c), inv));
    T.val[1][0] = MOD - mul(2, mul(mul(a, b), inv));
    T.val[1][1] = mul(B, inv);
    T.val[1][2] = MOD - mul(2, mul(mul(b, c), inv));
    T.val[2][2] = 1;
}

void build(int id, int l, int r){
    if(l == r) return st[id] = Matrix::identity(3), void();
    int mid = (l+r)>>1;
    build(id<<1, l, mid);
    build(id<<1|1, mid+1, r);
    st[id] = st[id<<1] * st[id<<1|1];
}

void upd(int id, int l, int r, int i, char m, int a, int b, int c, int inv){
    if(i < l || r < i) return;
    if(l == r){
        Matrix &T = st[id];
        if(m == 'G'){
            T = Matrix(3, 3);
            T.val[0][0] = mul(sqr(b), inv);
            T.val[0][1] = MOD - mul(mul(a, b), inv);
            T.val[0][2] = MOD - mul(mul(a, c), inv);
            T.val[1][0] = MOD - mul(mul(a, b), inv);
            T.val[1][1] = mul(sqr(a), inv);
            T.val[1][2] = MOD - mul(mul(b, c), inv);
            T.val[2][2] = 1;
        }
        else{
            T = Matrix(3, 3);
            int A = sqr(b), B = sqr(a);
            add(A, -sqr(a)); add(B, -sqr(b));
            T.val[0][0] = mul(A, inv);
            T.val[0][1] = MOD - mul(2, mul(mul(a, b), inv));
            T.val[0][2] = MOD - mul(2, mul(mul(a, c), inv));
            T.val[1][0] = MOD - mul(2, mul(mul(a, b), inv));
            T.val[1][1] = mul(B, inv);
            T.val[1][2] = MOD - mul(2, mul(mul(b, c), inv));
            T.val[2][2] = 1;
        }
        return;
    }
    int mid = (l+r)>>1;
    upd(id<<1, l, mid, i, m, a, b, c, inv);
    upd(id<<1|1, mid+1, r, i, m, a, b, c, inv);
    st[id] = st[id<<1|1] * st[id<<1];
}

Matrix get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return Matrix::identity(3);
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)>>1;
    return get(id<<1|1, mid+1, r, u, v) * get(id<<1, l, mid, u, v);
}

void solve(){
    cin >> n >> q;

    build(1, 1, n);

    FOR(i, 1, n){
        char m; int a, b, c; cin >> m >> a >> b >> c;
        int inv = sqr(a);
        add(inv, sqr(b));
        inv = pw(inv, MOD - 2);
        upd(1, 1, n, i, m, a, b, c, inv);
    }

    while(q--){
        int op; cin >> op;
        if(op == 1){
            int i, a, b, c; char m; cin >> i >> m >> a >> b >> c;
            int inv = sqr(a);
            add(inv, sqr(b));
            inv = pw(inv, MOD - 2);
            upd(1, 1, n, i, m, a, b, c, inv);
        }
        else{
            int x, y, l, r; cin >> x >> y >> l >> r;
            Matrix a = get(1, 1, n, l, r);
            Matrix b(3, 1);
            b.val[0][0] = x;
            b.val[1][0] = y;
            b.val[2][0] = 1;
            a = a * b;
            cout << a.val[0][0] << ' ' << a.val[1][0] << '\n';
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
