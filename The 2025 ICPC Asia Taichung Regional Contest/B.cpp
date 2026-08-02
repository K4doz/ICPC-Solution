/*
    Author: UIT.DemonSlayer
    NguyenThaiSon - University of Information Technology - CS18
    PhanMinhQuan - University of Information Technology - CS20
    PhungNgocNguyenDuc - University of Information Technology - CS20
*/

#include <bits/stdc++.h>
using namespace std;

// input/output
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
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
#define vii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vc vector<char>
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
#define set_on(n, i) ((n)  mask(i))
#define set_off(n, i) ((n) & ~mask(i))
#define firbit(x) 63 - __builtin_clzll(x)
//constant
#define N 200005
#define MOD 1000000007
#define mod 1000000007
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define oo 0x3f3f3f3f
#define base 31
#define BL 350
#define DemonSlayer 0
///template
const int d4x[4] = {-1, 0, 1, 0} , d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8y[8] = {0, 1, 1, 1, 0, -1, -1, -1};
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return 1; }; return 0; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return 1; }; return 0; }
void add(int &x, int y){x += y; if(x >= mod) x -= mod;}
void sub(int &x, int y){x -= y; if(x < 0) x += mod;}
int mul(int x, int y) {return 1LL * x * y % mod;}
int calPw(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

int n, m, leng, x, y;
pair<int, int> f[N];
double C[N];

void solve(){
    cin >> n >> m >> leng >> x >> y;
    for(int i = 1; i <= n; i++)
        cin >> f[i].fi >> f[i].se;
    sort(f + 1, f + n + 1);

    for(int i = 1; i <= n; i++){
        double cost = 1.0 * (f[i].se - f[i].fi) / x + 1.0 * (leng - f[i].se) / y;
        if(i == 1) C[i] = cost;
        else C[i] = min(C[i - 1], cost);
    }

    for(int i = 1; i <= m; i++){
        int st;
        cin >> st;

        int l = 1, r = n;
        double Ans = 1.0 * (leng - st) / y;
        while(l <= r){
            int m = l + r >> 1;
            if(f[m].fi <= st){
                Ans = min(Ans, C[m]);
                l = m + 1;
            }
            else
                r = m - 1;
        }

        cout << fixed << setprecision(8) << Ans << "\n";
    }
}

int main(){
    #define NAME "main"
    if(fopen(NAME".inp", "r")){
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }

    //srand(time(NULL));
    fastIO;

    if(DemonSlayer){
        int tc; cin >> tc;
        while(tc--){
            solve();
        }
    } else solve();
}
