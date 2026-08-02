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

bool check(int d, int m){
    if(m > 9) return 0;
    if(m == 9){
        if(17 <= d && d <= 30) return 0;
        return 1;
    }

    return 1;
}

void Solve() {
    string s; cin >> s;
    int d = (s[8] - '0') * 10 + (s[9] - '0');
    int m = (s[5] - '0') * 10 + (s[6] - '0');
    cout << (check(d, m)? "GOOD":"TOO LATE");
    cout << '\n';
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