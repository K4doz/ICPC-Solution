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
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {

        if (i + 3 < (int) (s.size())) 
            if (s[i] == 'k' && s[i + 1] == 'i' && s[i + 2] == 'c' && s[i + 3] == 'k') ++cnt;
    }
    cout << cnt;
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