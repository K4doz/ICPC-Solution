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
#define BIT(n, i) (((n) >> (i)) & 1)
#define set_on(n, i) ((n)  mask(i))
#define set_off(n, i) ((n) & ~mask(i))
//constant
#define N 200005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define base 31
#define Kadoc 1

int n;
char a[N];

void solve(){

    int cnta, cntb;
    cnta = cntb = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];

        if(a[i] == 'a') cnta++;
        if(a[i] == 'b') cntb++;
    }

    //cout << cnta << " " << cntb << "\n";

    if(cnta - cntb <= -2){
        cout << "alice\n";
        return;
    }

    if(cnta - cntb >= 1){
        cout << "bob\n";
        return;
    }

    if(n == 1){
        if(a[1] == '.')
            cout << "alice\n";
        else
            cout << "bob\n";
        return;
    }



    int valL, valR;
    valL = valR = 0;

    if(a[1] == 'a' || a[2] == 'b') valL = 1;
    if(a[1] == 'b' || a[2] == 'a') valL = 2;

    if(a[n] == 'a' || a[n - 1] == 'b') valR = 1;
    if(a[n] == 'b' || a[n - 1] == 'a') valR = 2;

    int Sum = 0;
    if(valL == 1 && valR == 1) Sum = 1;
    else if(valL == 1 && valR == 0) Sum = 1;
    else if(valL == 0 && valR == 1) Sum = 1;
    else if(valL == 2 && valR == 2) Sum = -1;
    else Sum = 0;



    if(Sum > cnta - cntb){
        cout << "alice\n";
        return;
    }

    cout << "bob\n";
}

int main(){
    #define NAME "main"
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
