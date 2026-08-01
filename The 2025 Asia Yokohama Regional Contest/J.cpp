/*
    The 2025 Asia Yokohama Regional Contest - Problem J
*/


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
#define set_on(n, i) ((n) | mask(i))
#define set_off(n, i) ((n) & ~mask(i))
//constant
#define N 1005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define base 31
#define Kadoc 1

int n, m;
int a[N][N], row[N], col[N], Ans[N][N];

bool oke(int x, int y, int u, int v){
    vector<int> pos(4, -1);
    for(int i=x; i<=u; ++i){
        for(int j=y; j<=v; ++j){
            if(!a[i][j]) continue;
            int k = (x == u? j:i);
            if(pos[a[i][j]] != -1 && ((k + pos[a[i][j]])&1)) return 0;
            pos[a[i][j]] = k;
        }
    }

    for(int l=1; l<4; ++l){
        if(pos[l] != -1){
            for(int i=x; i<=u; ++i){
                for(int j=y; j<=v; ++j){
                    int k = (x == u? j:i);
                    if((k + pos[l]) % 2 == 0 && a[i][j] != 0 && a[i][j] != l) return 0;
                }
            }
        }
    }
    return 1;
}

bool CC(int x){
    // ??, CC, C?
    return x == 1 || x == 4 || x == 5;
}

bool CI(int x){
    // ??, C?, I?, CI, CI?
    return x == 1 || x == 3 || x == 5 || x == 6 || x == 7;
}

bool IP(int x){
    // ??, I?, P?, IP, IP?
    return x == 1 || x == 3 || x == 9 || x == 10 || x == 11;
}

bool CP(int x){
    // ??, C?, P?, CP, CP?
    return x == 1 || x == 5 || x == 9 || x == 12 || x == 13;
}

char Map(int x){
    if(x == 1) return 'I';
    if(x == 2) return 'C';
    return 'P';
}

void fillRow(int x, int y, int k){
    int posX = -1, posY = -1;
    for(int j=1; j<=m; ++j){
        if(a[k][j] == x){
            posX = j&1;
        }
        if(a[k][j] == y){
            posY = j&1;
        }
    }

    if(posX != -1){
        for(int j=1; j<=m; ++j){
            Ans[k][j] = a[k][j];
            if((j + posX)&1){
                if(!a[k][j]) Ans[k][j] = y;
            }
            else{
                if(!a[k][j]) Ans[k][j] = x;
            }
        }
    }
    else if(posY != -1){
        for(int j=1; j<=m; ++j){
            Ans[k][j] = a[k][j];
            if((j + posY)&1){
                if(!a[k][j]) Ans[k][j] = x;
            }
            else{
                if(!a[k][j]) Ans[k][j] = y;
            }
        }
    }
    else{
        for(int j=1; j<=m; ++j){
            Ans[k][j] = a[k][j];
            if(!a[k][j]){
                if(j&1) Ans[k][j] = x;
                else Ans[k][j] = y;
            }
        }
    }
}

void fillCol(int x, int y, int k){
    int posX = -1, posY = -1;
    for(int i=1; i<=n; ++i){
        if(a[i][k] == x){
            posX = i&1;
        }
        if(a[i][k] == y){
            posY = i&1;
        }
    }

    if(posX != -1){
        for(int i=1; i<=n; ++i){
            Ans[i][k] = a[i][k];
            if((i + posX)&1){
                if(!a[i][k]) Ans[i][k] = y;
            }
            else{
                if(!a[i][k]) Ans[i][k] = x;
            }
        }
    }
    else if(posY != -1){
        for(int i=1; i<=n; ++i){
            Ans[i][k] = a[i][k];
            if((i + posY)&1){
                if(!a[i][k]) Ans[i][k] = x;
            }
            else{
                if(!a[i][k]) Ans[i][k] = y;
            }
        }
    }
    else{
        for(int i=1; i<=n; ++i){
            Ans[i][k] = a[i][k];
            if(!a[i][k]){
                if(i&1) Ans[i][k] = x;
                else Ans[i][k] = y;
            }
        }
    }
}

void printAns(){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cout << Map(Ans[i][j]);
        }
        cout << '\n';
    }
}

void solve(){
    cin >> n >> m;

    for(int i=1; i<=n; ++i) row[i] = 0;
    for(int j=1; j<=m; ++j) col[j] = 0;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            char c; cin >> c;
            if(c == '?') a[i][j] = 0;
            else if(c == 'I') a[i][j] = 1;
            else if(c == 'C') a[i][j] = 2;
            else a[i][j] = 3;

            row[i] |= (1 << a[i][j]);
            col[j] |= (1 << a[i][j]);
        }
    }

    // II, PP -> sai
    {
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(j > 1 && (a[i][j]&1) && a[i][j] == a[i][j-1]){
                    cout << "no\n";
                    return;
                }

                if(i > 1 && (a[i][j]&1) && a[i][j] == a[i-1][j]){
                    cout << "no\n";
                    return;
                }
            }
        }
    }

    // giai tren hang
    {
        for(int i=1; i<=n; ++i){
            // toan C
            if(CC(row[i])){
                bool ok = 1;
                for(int k=((i&1)? 1:2); k<=n; k+=2){
                    if(!CC(row[k])){
                        ok = 0;
                        break;
                    }
                }
                for(int k=(i&1)+1; k<=n; k+=2){
                    if(!IP(row[k]) || !oke(k, 1, k, m)){
                        ok = 0;
                        break;
                    }
                }
                if(ok == 1){
                    cout << "yes\n";

                    for(int k=((i&1)? 1:2); k<=n; k+=2){
                        fillRow(2, 2, k);
                    }
                    for(int k=(i&1)+1; k<=n; k+=2){
                        fillRow(1, 3, k);
                    }
                    printAns();

                    return;
                }
            }

            // C, I xen ke
            if(CI(row[i]) && oke(i, 1, i, m)){
                bool ok = 1;
                for(int k=((i&1)? 1:2); k<=n; k+=2){
                    if(!CI(row[k]) || !oke(k, 1, k, m)){
                        ok = 0;
                        break;
                    }
                }
                for(int k=(i&1)+1; k<=n; k+=2){
                    if(!CP(row[k]) || !oke(k, 1, k, m)){
                        ok = 0;
                        break;
                    }
                }
                if(ok == 1){
                    cout << "yes\n";

                    for(int k=((i&1)? 1:2); k<=n; k+=2){
                        fillRow(1, 2, k);
                    }
                    for(int k=(i&1)+1; k<=n; k+=2){
                        fillRow(2, 3, k);
                    }
                    printAns();

                    return;
                }
            }

            // C, P xen ke
            if(CP(row[i]) && oke(i, 1, i, m)){
                bool ok = 1;
                for(int k=((i&1)? 1:2); k<=n; k+=2){
                    if(!CP(row[k]) || !oke(k, 1, k, m)){
                        ok = 0;
                        break;
                    }
                }
                for(int k=(i&1)+1; k<=n; k+=2){
                    if(!CI(row[k]) || !oke(k, 1, k, m)){
                        ok = 0;
                        break;
                    }
                }
                if(ok == 1){
                    cout << "yes\n";

                    for(int k=((i&1)? 1:2); k<=n; k+=2){
                        fillRow(2, 3, k);
                    }
                    for(int k=(i&1)+1; k<=n; k+=2){
                        fillRow(1, 2, k);
                    }
                    printAns();

                    return;
                }
            }
        }
    }

    // giai tren cot
    {
        for(int i=1; i<=m; ++i){
            // toan C
            if(CC(col[i])){
                bool ok = 1;
                for(int k=((i&1)? 1:2); k<=m; k+=2){
                    if(!CC(col[k])){
                        ok = 0;
                        break;
                    }
                }
                for(int k=(i&1)+1; k<=m; k+=2){
                    if(!IP(col[k]) || !oke(1, k, n, k)){
                        ok = 0;
                        break;
                    }
                }
                if(ok == 1){
                    cout << "yes\n";

                    for(int k=((i&1)? 1:2); k<=m; k+=2){
                        fillCol(2, 2, k);
                    }
                    for(int k=(i&1)+1; k<=m; k+=2){
                        fillCol(1, 3, k);
                    }
                    printAns();

                    return;
                }
            }

            // C, I xen ke
            if(CI(col[i]) && oke(1, i, n, i)){
                bool ok = 1;
                for(int k=((i&1)? 1:2); k<=m; k+=2){
                    if(!CI(col[k]) || !oke(1, k, n, k)){
                        ok = 0;
                        break;
                    }
                }
                for(int k=(i&1)+1; k<=m; k+=2){
                    if(!CP(col[k]) || !oke(1, k, n, k)){
                        ok = 0;
                        break;
                    }
                }
                if(ok == 1){
                    cout << "yes\n";

                    for(int k=((i&1)? 1:2); k<=m; k+=2){
                        fillCol(1, 2, k);
                    }
                    for(int k=(i&1)+1; k<=m; k+=2){
                        fillCol(2, 3, k);
                    }
                    printAns();

                    return;
                }
            }

            // C, P xen ke
            if(CP(col[i]) && oke(1, i, n, i)){
                bool ok = 1;
                for(int k=((i&1)? 1:2); k<=m; k+=2){
                    if(!CP(col[k]) || !oke(1, k, n, k)){
                        ok = 0;
                        break;
                    }
                }
                for(int k=(i&1)+1; k<=m; k+=2){
                    if(!CI(col[k]) || !oke(1, k, n, k)){
                        ok = 0;
                        break;
                    }
                }
                if(ok == 1){
                    cout << "yes\n";

                    for(int k=((i&1)? 1:2); k<=m; k+=2){
                        fillCol(2, 3, k);
                    }
                    for(int k=(i&1)+1; k<=m; k+=2){
                        fillCol(1, 2, k);
                    }
                    printAns();

                    return;
                }
            }
        }
    }

    cout << "no\n";
}

int main(){
    #define NAME "TASK"
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