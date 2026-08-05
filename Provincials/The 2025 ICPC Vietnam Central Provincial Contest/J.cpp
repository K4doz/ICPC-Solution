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
#define N 105
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define base 31
#define Kadoc 0

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m;
char a[N][N];
int d[N][N][4];

struct Node{
    int x, y, k;

    Node() = default;
    Node(int _x, int _y, int _k){
        x = _x;
        y = _y;
        k = _k;
    }
};

bool insize(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void solve(){
    cin >> n >> m;
    pii s = pii(-1, -1), f = pii(-1, -1);
    FOR(i, 1, n) FOR(j, 1, m){
        cin >> a[i][j];
        if(a[i][j] == 'S') s = pii(i, j);
        if(a[i][j] == 'D') f = pii(i, j);
    }

    queue<Node> q;
    memset(d, -1, sizeof d);
    d[s.fi][s.se][3] = 0;
    q.emplace(s.fi, s.se, 3);

    while(q.size()){
        auto [x, y, k] = q.front(); q.pop();

        if(pii(x, y) == f) return cout << d[x][y][k] << '\n', void();

        FOR(i, 0, 3){
            int nx = x + dx[i], ny = y + dy[i], nk = k;

            if(!insize(nx, ny)) continue;
            if(a[nx][ny] == '+') nk--;
            if(nk < 1) continue;

            if(d[nx][ny][nk] < 0){
                d[nx][ny][nk] = d[x][y][k] + 1;
                q.emplace(nx, ny, nk);
            }
        }
    }

    cout << -1;
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
