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


void Solve() {
    ll a, b;
    double c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    c *= 100;
    d *= 100;
    ll x = int(d + 0.5) * a;
    ll y = int(c + 0.5) * b;
    if(x > y) cout << "JAKARTA";
    else if(x < y) cout << "TAOYUAN";
    else cout << "SAME";
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