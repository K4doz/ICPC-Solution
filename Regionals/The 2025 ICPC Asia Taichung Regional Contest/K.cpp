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
#define N 100005
#define MOD 1000000007
#define mod 1000000007
#define INF 1000001
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
///
int n, m, q;
char a[1003][1003];
int cnt[1000006];

void Cal(int i, int j, int type){
    int Ans = 0;
    int res = 1;
    int val = (int) a[i][j] - '0';
    bool oke = false;
    int x = i;
    int y = j;
    while(true){
        x += d8x[type];
        y += d8y[type];
        if(x < 1 || x > n || y < 1 || y > m) break;
        int c = a[x][y];
        if(c == '+'){
            if(oke) return;
            if(val != 0 && res > INF / val) return;
            res *= val;
            if(Ans > INF - res) return;
            Ans += res;
            res = 1;
            val = 0;
            oke = true;
        }
        else if(c == '*'){
            if(oke) return;
            if(val != 0 && res > INF / val) return;
            res *= val;
            val = 0;
            oke = true;
        }
        else{
            val = val * 10 + (int) c - '0';
            if(val != 0 && res > INF / val) return;
            if(Ans > INF - res * val) return;
            if(Ans + res * val <= INF)
                cnt[Ans + res * val]++;

//            if(i == 1 && j == 4)
//                cout << Ans + res * val << "\n";
            oke = false;
        }
    }
}

void solve(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == '+' || a[i][j] == '*') continue;
            cnt[(int) a[i][j] - '0']++;

            for(int k = 0; k <= 7; k++)
                Cal(i, j, k);
        }
    }

    for(int i = 1; i <= q; i++){
        int x;
        cin >> x;
        cout << cnt[x] << "\n";
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
