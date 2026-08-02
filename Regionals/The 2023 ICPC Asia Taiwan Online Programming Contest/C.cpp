#include<bits/stdc++.h>
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FORD(i, l, r) for (int i = l; i >= r; i--)
#define ll long long 
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()

const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
using namespace std;

const ll Base = 311;
const ll Base2 = 31;

int dp[N][350];

ll HH[N], Pow[N], Pow2[N], HH2[N];
string s, b;
int n;
pair<ll, ll> getHash(int l, int r) {

    return {(HH[r] - HH[l - 1] * Pow[r - l + 1] + mod * mod) % mod,
                (HH2[r] - HH2[l - 1] * Pow2[r - l + 1] + mod * mod)% mod};

}


bool Comp(int l, int r, int LL, int RR) {
    if(r > n || RR > n) return false;
   // cout << l << " " << r << " " << LL << " " << RR << endl;
    int len1 = (r - l + 1);
    int len2 = (RR - LL + 1);

    if(len2 > len1) return true;
    if (len2 < len1) return false;

    int Le = 0,  Ri = len2 - 1;

    if (getHash(l, r) == getHash(LL, RR)) return true;

    int Ans = -1;

  //  cout << "WW" << endl;

    while (Le <= Ri) {
        int mid = (Le + Ri) / 2;
        //cout << mid << endl;
        if (getHash(l, l + mid) == getHash(LL, LL + mid)) {
            Ans = mid;
            Le = mid + 1;
        }
        else Ri = mid - 1;
    }

 //   cout << Ans << endl;
    return (s[l + Ans + 1] <= s[LL + Ans + 1]);

}

void Solve() {
    cin >> s >> b;
    if (s == "0") {
        cout << 0;
        return;
    }
    int len = b.size();
    s += b;
    n = s.size();
    s = ' ' + s;
    Pow[0] = 1;
    Pow2[0] = 1;
    HH[0] = 0;
    HH2[0] = 0;
    FOR(i, 1, n)
        HH[i] = (HH[i - 1] * Base + (s[i] - '0') + 1) % mod, 
        Pow[i] = Pow[i - 1] * Base % mod,
        HH2[i] = (HH2[i - 1] * Base2 + (s[i] - '0') + 1) % mod, 
        Pow2[i] = Pow2[i - 1] * Base2 % mod;


    // auto[x, y] = getHash(8, 8);
    // auto[xx, yy] = getHash(11, 11);

    // cout << x << " " << y << " " << xx << " " << yy << endl;

    // cout << Comp(8, 10, 11, 13);

    // cout << endl;

    memset(dp, 0x3f, sizeof(dp));

    //cout << dp[10][2] << endl;
    dp[n - len + 1][len] = 0;
    //cout << n - len + 1 << " " << len << endl;
        for (int j = n - len; j >= 1; j--) {
            for (int i = 0; i <= 50; i++) {
            if (s[j] == '0') continue;
            for (int k = i; k <= 50; k++)
                if (Comp(j, j + i, j + i + 1, j + i + 1 + k)) {

                   // cout << "SS " << s.substr(j, i + 1) << " " << s.substr(j + i + 1, k + 1) << endl;

                   // cout << "LEN " << j + i + 1 << "  " << k + 1 << endl;
                    dp[j][i + 1] = min(dp[j][i + 1], dp[j + i + 1][k + 1] + 1);
                   // cout << dp[j][i + 1] << endl;
                }
                
           //if (dp[j][i] != -1) cout << j << " " << i << " " << dp[j][i] << endl;
            
            //if (dp[j][i + 1] < dp[0][0]) cout << j << " " << i << " " << dp[j][i] << endl; 
        }
    }
    int Ans = dp[0][0];
    FOR(i, 0, 50)
       Ans = min(Ans, dp[1][i]);
    if (Ans != dp[0][0]) cout << Ans - 1;
    else 
    cout << "NO WAY";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen("task.inp", "r")){
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }

    int T = 1;
    while(T--){
        Solve();
    }
}