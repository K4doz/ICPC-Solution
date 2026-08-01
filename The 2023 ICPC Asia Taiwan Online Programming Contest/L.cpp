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
    int n;
    cin >> n;
    vector<int> V, T;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        V.push_back(x);
        T.push_back(y);
    }    

    sort(V.begin(),V.end());
    sort(T.begin(),T.end());

    cout << V[(n - 1) / 2] << " " << T[(n - 1) / 2];
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