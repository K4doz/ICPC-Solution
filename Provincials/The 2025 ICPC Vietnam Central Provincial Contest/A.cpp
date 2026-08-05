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

int n, k;
int a[22];
int C[22][22];
int dp[22][22][22][44];

void add(int &a, int b){
    a += b;
    if(a >= MOD) a -= MOD;
    if(a < 0) a += MOD;
}

void solve(){
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    C[0][0] = 1;
    FOR(i, 1, 20){
        FOR(j, 0, i){
            if(j == 0 || i == j) C[j][i] = 1;
            else{
                C[j][i] = C[j-1][i-1];
                add(C[j][i], C[j][i-1]);
            }
        }
    }

    // dp(i, p, q, t) la [1..i], co p thang dang mo, q thang da dong, a[i] = t
    dp[0][0][0][0] = 1;
    FOR(i, 0, n-1){
        FOR(q, 0, k){
            FOR(p, 0, k - q){
                FOR(np, 0, k - p - q){
                    FOR(nq, 0, p + np){
                        FOR(t, a[i] + p, a[i+1] + p + np - 1){
                            if(!dp[i][p][q][t]) continue;

                            int Res = dp[i][p][q][t];
                            Res = 1ll * Res * C[np][k - p - q] % MOD;
                            Res = 1ll * Res * C[nq][p + np] % MOD;

                            add(dp[i+1][p + np - nq][q + nq][a[i+1] + p + np], Res);
                        }
                    }
                }
            }
        }
    }

    int Ans = 0;
    FOR(t, 0, 40) add(Ans, dp[n][0][k][t]);

    cout << Ans; el;
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
