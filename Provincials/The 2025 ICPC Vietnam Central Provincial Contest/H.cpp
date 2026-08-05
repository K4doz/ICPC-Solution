#include<bits/stdc++.h>
using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define BIT(x, i) (((x) >> (i)) & (1LL))
#define MASK(i) ((1LL) << (i))
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)

const int N = 200005;
const ll INF = 1e18 + 7;

int n, T;
int cnt = 0;
bool used[15];
int V[N];
int Sum[5];

void backtrack(int id){

    if(id > n){
        if (Sum[1] == T && Sum[2] == T && Sum[3] == T) {

            for(int i = 1; i <= n; i++) cout << V[i] << " ";
            cout << "\n";
            cnt++;
        }
        return;
    }

    for(int i = 1; i <= n; i++) if(!used[i]){
        V[id] = i;
        used[i] = true;
         if (id <= n / 3 + 1) Sum[1] += V[id];
            if (id >= n / 3 + 1 && id <= 2 * n / 3 + 1)
            Sum[2] += V[id];
        if (id >= 2 * n / 3 + 1 && id <= n || id == 1)
            Sum[3] += V[id];
        bool oke = true;
        if (id == n / 3 + 1 && Sum[1] != T) oke = false;
        if (id == 2 * n / 3 + 1 && Sum[2] != T) oke = false;
        if (oke)
            backtrack(id + 1);
        used[i] = false;
        if (id <= n / 3 + 1) Sum[1] -= V[id];
            if (id >= n / 3 + 1 && id <= 2 * n / 3 + 1)
            Sum[2] -= V[id];
        if (id >= 2 * n / 3 + 1 && id <= n || id == 1)
            Sum[3] -= V[id];
    }
}

void Solve(){
    cin >> n >> T;
    backtrack(1);

    if(cnt == 0) cout << -1 << "\n";
    else cout << cnt << "\n";

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #define TASK "test"
    if(fopen(TASK".inp", "r")){
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }

    Solve();

    return 0;
}
