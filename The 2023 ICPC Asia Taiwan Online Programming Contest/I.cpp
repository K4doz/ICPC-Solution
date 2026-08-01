#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int mod = 1e9 + 7;
int n, a[205], fact[205];
int C[205][205], dp[205][205][205];

void add(int &u, int v) {
    u += v;
    if (u >= mod) u -= mod;
}

void del(int &u, int v) {
    u -= v;
    if (u < 0) u += mod;
}

ll Pow(ll n, ll k) {
    if (k == 0) return 1;
    if (k == 1) return n;

    ll res = Pow(n, k / 2);
    res = res * res % mod;

    if ((k % 2) == 1) res = res * n % mod;
    return res;
}

void Solve() {
     cin >> n;
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[0][i] = 1;
        for (int j = 1; j <= i; j++) {
            C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]) % mod;
        }
    }
    map<int, int> Dem;
    Dem.clear();
    int cnt = 0;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            ++cnt;
            Dem[a[i]]++;
        }

    }
    int numX = 0;
    for (auto[u, v] : Dem)
        if (v == 1) ++numX;


    fact[0] = 1;
    for (int i = 1; i <= 2 * n; i++)
        fact[i] = 1ll * fact[i - 1] * i % mod;

    dp[0][0][0] = 1;

    for (int i = 0; i <= 2 * n; i++) {

        for (int x = 0; 2 * x <= i; x++)
            for (int y = 0; 2 * (x + y) <= i; y++)
                if (dp[i][x][y] == 0) continue;
                else {
                    /// them 1 cap(da duoc chon)

                    if (((a[i + 1] == 0 && a[i + 2] > 0) || (a[i + 1] > 0 && a[i + 2] == 0)) && Dem[max(a[i + 1], a[i + 2])] == 1)
                        add(dp[i + 2][x + 1][y], dp[i][x][y]);

                    add(dp[i + 1][x][y], dp[i][x][y]);

                    if (a[i + 1] == 0 && a[i + 2] == 0)
                        add(dp[i + 2][x][y + 1], 1ll * dp[i][x][y] * (n - (int)Dem.size() - y) % mod);

                }

    }
    n = 2 * n;
    int Ans = 0;
    for (int x = 0; 2 * x <= n; x++)
        for (int y = 0; 2 * (x + y) <= n; y++) if (dp[n][x][y]) {
            int numY = n - 2 * y - (int)Dem.size() * 2;
            int O_trong = n - cnt - 2 * y - x;

            int numW = dp[n][x][y];

            numW = 1ll * numW * fact[O_trong] % mod;

            numW = 1ll * numW * Pow(Pow(2, numY / 2), mod - 2) % mod;

            if ((x + y) % 2 == 0)
                add(Ans, numW);
            else del(Ans, numW);
        }

    cout << Ans << endl;

    memset(dp, 0, sizeof(dp));
    memset(C, 0, sizeof(C));
    memset(fact, 0, sizeof(fact));
    memset(a, 0, sizeof(a));

}

int main() {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);

    int T;
    cin >> T;
    while (T -- ) Solve();





}
