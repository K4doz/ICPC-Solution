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

int n;

void solve(){

    cin >> n;
    int NN = n;
    vector<int> S;
    if ((n / 200) % 2 == 1) {

        while (n >= 400) n -= 200, n -= 200, S.push_back(200), S.push_back(200);


    }

    //cout << n << endl;
    
    while (n >= 1000) S.push_back(500), S.push_back(500), n -= 1000;
    int val = 1;
 
   // cout << n << endl;
    do {
 
        int res = n % 10;
        n /= 10;
 
        if (res % 2 == 1) {
 
            vector<int> V = S;

            FOR(i, 1, res) V.push_back(1 * val);
 
            int remain = n * 10 * val;
 
            while (remain != 0) {
                V.push_back(val * 10);
                remain -= val * 10;
            }

            int Tot = 0;
            for (int v : V) Tot += v;
 
            while (Tot < NN) V.push_back(1), Tot++;
 
            cout << V.size() << endl;
            for (int v : V) cout << v << " ";
            return;
        }
 
        if (res == 2) {
            vector<int> V = S;
            V.push_back(2 * val);
 
            int remain = n * 10 * val;
 
            while (remain != 0) {
                V.push_back(val * 10);
                remain -= val * 10;
            }
            int Tot = 0;
            for (int v : V) Tot += v;
 
            while (Tot < NN) V.push_back(1), Tot++;
 
            cout << V.size() << endl;
            for (int v : V) cout << v << " ";
            return;
        }
 
        if (res == 6) {
            vector<int> V = S;
            V.push_back(5 * val);
            V.push_back(1 * val);
 
            int remain = n * 10 * val;
 
            while (remain != 0) {
                V.push_back(val * 10);
                remain -= val * 10;
            }
 
            int Tot = 0;
            for (int v : V) Tot += v;
 
            while (Tot < NN) V.push_back(1), Tot++;
            cout << V.size() << endl;
            for (int v : V) cout << v << " ";
            return;
        }
 
        if (res == 8) {
            vector<int> V = S;
            V.push_back(5 * val);
            V.push_back(1 * val);
            V.push_back(2 * val);
 
            int remain = n * 10 * val;
 
            while (remain != 0) {
                V.push_back(val * 10);
                remain -= val * 10;
            }
 
            int Tot = 0;
            for (int v : V) Tot += v;
 
            while (Tot < NN) V.push_back(1), Tot++;
 
            cout << V.size() << endl;
            for (int v : V) cout << v << " ";
            return;
        }
 
        val = val * 10;
    }
    while (n != 0);
 
    cout << "splittable";
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