/*
    The 2025 Asia Yokohama Regional Contest - Problem H
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
#define N 1003
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define base 31
#define Kadoc 1

int n, m, k;
int a[N][N];

bool check(int x, int y, int xx, int yy){
    for(int i = x; i <= xx; i++)
        for(int j = y; j <= yy; j++)
            if(a[i][j] == 0) return false;
    return true;
}

void fill(int x, int y, int xx, int yy){
    for(int i = x; i <= xx; i++)
        for(int j = y; j <= yy; j++)
            a[i][j] = 0;
}

void Cal(int x, int y){
    //cout << x << " " << y << "\n";
    ///Case 1: Top 
    if(check(x, y, x, y + k - 1) && check(x, y, x + k - 1, y) && check(x, y + k - 1, x + k - 1, y + k - 1)){
        fill(x, y, x, y + k - 1);
        fill(x, y, x + k - 1, y);
        fill(x, y + k - 1, x + k - 1, y + k - 1);
        return;
    }

    ///Case 2: Bot
    if(check(x, y, x, y + k - 1) && check(x, y, x + k - 1, y) && check(x + k - 1, y, x + k - 1, y + k - 1)){
        fill(x, y, x, y + k - 1);
        fill(x, y, x + k - 1, y);
        fill(x + k - 1, y, x + k - 1, y + k - 1);
        return;
    }

    ///Case 3: Right
    if(check(x, y, x, y + k - 1) && check(x, y + k - 1, x + k - 1, y + k - 1) && check(x + k - 1, y, x + k - 1, y + k - 1)){
        fill(x, y, x, y + k - 1);
        fill(x, y + k - 1, x + k - 1, y + k - 1);
        fill(x + k - 1, y, x + k - 1, y + k - 1);
        return;
    }

    ///Case 4: 
    if(check(x, y, x + k - 1, y) && check(x, y + k - 1, x + k - 1, y + k - 1) && check(x + k - 1, y, x + k - 1, y + k - 1)){
        fill(x, y, x + k - 1, y);
        fill(x, y + k - 1, x + k - 1, y + k - 1);
        fill(x + k - 1, y, x + k - 1, y + k - 1);
        return;
    }
}

void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if(c == '.') a[i][j] = 0;
            else a[i][j] = 1;
        }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i][j] == 1)
                Cal(i, j);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i][j] == 1){
                cout << "no\n";
                return;
            }

    cout << "yes\n";

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