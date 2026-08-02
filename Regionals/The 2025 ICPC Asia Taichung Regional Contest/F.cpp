/// Author : Nguyễn Thái Sơn - K18 - KHMT - UIT
/// Training ICPC 2024

#include<bits/stdc++.h>

/// #pragma GCC optimize("O3,unroll-loops")
/// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define fi first
#define se second
#define TASK "test"
#define pb push_back
#define EL cout << endl
#define Ti20_ntson int main()
#define in(x) cout << x << endl
#define all(x) (x).begin(),(x).end()
#define getbit(x, i) (((x) >> (i)) & 1)
#define cntbit(x) __builtin_popcount(x)
#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FORD(i,l,r) for (int i = l; i >= r; i--)
#define Debug(a,n) for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> vii;
typedef unsigned long long ull;
typedef vector<vector<int>> vvi;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }

const int N = 3e5 + 5;
const int oo = INT_MAX;
const int mod = 1e9 + 7;
const int d4x[4] = {-1, 0, 1, 0} , d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int pre[N], suf[N], n, a[N];

inline void Read_Input() {
    cin >> n;
    FOR(i, 1, n)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        pre[i] = __gcd(pre[i - 1], a[i]);

    for (int i = n; i >= 1; i--)
        suf[i] = __gcd(suf[i + 1], a[i]);


    ll Ans = pre[n];

    for (int i = 2; i < n; i++) {

        Ans += min(pre[i], suf[i]);
    }
    cout << Ans;

}

inline void Solve() {

}

Ti20_ntson {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
//    cin >> T;
    while (T -- ) {
        Read_Input();
        Solve();
    }
}
