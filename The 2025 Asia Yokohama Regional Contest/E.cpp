/*
    The 2025 Asia Yokohama Regional Contest - Problem H
*/

#include<bits/stdc++.h>
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FORD(i, l, r) for (int i = l; i >= r; i--)
#define ll long long 
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()

const int N = 1e6 + 5;
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
ll a, b, c, k;
vector<pll> Res;

bool Cal(ll a, ll b, ll c, ll m){
    long long x = 1LL * b * m / a;
    long long y = 1LL * c * m / a;

    //cout << m << " " << x << " " << y << "\n";
    //return (m * (b  / a * m) * (c / a * m)) >= k;
    if((double) log(x) + log(y) + log(m) > log(k)) return true;
    return 1LL * m * x * y >= k;
}

void Exe(ll a, ll b, ll c, ll k){
    ll l = 1, r = 1000000000, Ans = 1000000000;
    
    //cout << Cal(a, b, c, 4) << "\n";
    // return;
    while(l <= r){
        ll m = (l+r)>>1;
        if(Cal(a, b, c, m)){
            Ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    Res.push_back({a, Ans});
}

bool cmp(pii x, pii y){
    return 1LL * x.fi * y.se < 1LL * x.se * y.fi;
}

void Solve(){
    Res.clear();
    cin >> a >> b >> c >> k;

    Exe(a, b, c, k);
    Exe(b, c, a, k);
    Exe(c, b, a, k);

    sort(ALL(Res), cmp);
    //for(pll Pos : Res) cout << Pos.fi << " " << Pos.se << "\n";
    pll Ans = Res.back(); 
    ll c = __gcd(Ans.fi, Ans.se);
    Ans.fi /= c;
    Ans.se /= c;
    cout << Ans.fi << " " << Ans.se << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen("task.inp", "r")){
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }

    int T; cin >> T;
    while(T--){
        Solve();
    }
}