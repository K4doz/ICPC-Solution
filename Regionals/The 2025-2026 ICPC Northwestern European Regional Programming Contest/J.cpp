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
#define N 100005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define base 31
#define Kadoc 0

int n, k, q, Ans[N], p[N], l[N], r[N];

vector<tuple<int, int, int, int>> V;

set<pair<int, int>> K_best, Store;

void solve(){

    cin >> n >> k >> q;

    FOR(i, 1, q) {
        cin >> p[i] >> l[i] >> r[i];


        V.push_back({l[i], -1, p[i], i});

        V.push_back({r[i], 1, p[i], i});

    }

    sort(V.begin(), V.end());

    int n_house = n;


    for (auto[ti, fl, que, num] : V) {
        if (fl == -1) {
            n_house--;

        }
        else {

            if (n_house == 0) 
                Ans[num] = 1;

            n_house++;
        }
    }

   // cout << "???" << endl;
    int cnt = 0;

    for (auto[ti, fl, que, num] : V) {

        if (fl == -1 && Ans[num] == 1) ++cnt;

        if (fl == 1 && Ans[num] == 1) --cnt;

        if (cnt > k) {

            cout << "impossible";
            return;
        }
    }

    FOR(i, 1, q)
        cout << Ans[i];

}

int main(){
    #define NAME "TASK"
    if(fopen(NAME".inp", "r")){
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".ans", "w", stdout);
    }

   // cout << "111" << endl;
    fastIO;
    
    if(Kadoc){
        int tc; cin >> tc;
        while(tc--){
            solve();
        }
    } else solve();
}