/// Author : Nguyễn Thái Sơn - K18 - KHMT - UIT
/// Training ICPC 2024

#include<bits/stdc++.h>

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

const int N = 5e5 + 5;
const int oo = 1e9 + 7; // Tránh tràn số khi cộng/trừ với INT_MAX

int par[N], cnt[N], st[N], left_pos[N], right_pos[N], n, a[N];// Đổi tên left/right tránh đụng độ thư viện
int h[N];
vector<vii> V;

struct Segmenttree {
    struct Node {
        int lazy;
        int val;
    } nodes[N * 4];

    void down(int id) {
        int t = nodes[id].lazy;
        nodes[id*2].lazy += t;
        nodes[id*2].val += t;

        nodes[id*2+1].lazy += t;
        nodes[id*2+1].val += t;

        nodes[id].lazy = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (v < l || r < u) return;
        if (u <= l && r <= v) {
            nodes[id].val += val;
            nodes[id].lazy += val;
            return;
        }
        int mid = (l + r) / 2;
        down(id);
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        nodes[id].val = max(nodes[id*2].val, nodes[id*2+1].val);
    }

    int get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return -oo; // Sửa -INFINITY thành -oo
        if (u <= l && r <= v) return nodes[id].val;
        
        int mid = (l + r) / 2;
        down(id);
        return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
    }
} it;

int Find(int u) {
    if (par[u] < 0) return u;
    return par[u] = Find(par[u]);
}

void Merge(int num, int u, int v) {
    int id = Find(u);

    it.update(1, 1, n, right_pos[id] - cnt[id] + 1, right_pos[id], num - st[id]);
    st[id] = num;

    if (v <= n) {
        int id2 = Find(v);
        it.update(1, 1, n, right_pos[id2] - cnt[id2] + 1, right_pos[id2], num - st[id2]);

        par[id] = id2; // Sửa lỗi ic2 -> id2
        cnt[id2] += cnt[id];
        left_pos[id2] = min(left_pos[id2], left_pos[id]);
        right_pos[id2] = max(right_pos[id2], right_pos[id]);
        st[id2] = num;
    }
}

void Del(int num, int u) {
    int id = Find(u);

    it.update(1, 1, n, right_pos[id] - cnt[id] + 1, right_pos[id], num - st[id]);

    st[id] = num;
    cnt[id]--;
}

void Solve() {
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
        V.push_back({a[i], i});

    }
    FOR(i, 1, n - 1) {
        cin >> h[i];
        V.push_back({h[i], -i}); 
    }
    h[n] = n;
    V.push_back({h[n], -n}); 
    sort(all(V));

    FOR(i, 1, n) {
        par[i] = -1; 
        left_pos[i] = i;
        right_pos[i] = i;
        st[i] = 0;
        cnt[i] = 1;
    }

    int ct = 0; 
    FOR(i, 0, n) {
        while (ct < (int)(V.size())) {
            auto [dc, type] = V[ct];

            if (dc > i) break;

           //
           // cout << i << " " << dc << " " << type << endl;
            int id = abs(type);

            if (type < 0)
                Merge(i, id, id + 1);
            else 
                Del(i, id);

            ct++;

            //cout << "$ "; 
        }
       

    }
    for(int j = 1; j <= n; j++)   cout << it.get(1, 1, n, j, j) << " ";
         cout << endl;
    EL;
}

Ti20_ntson {
   // freopen("task.inp", "r", stdin);
   // freopen("task.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    while (T--) {
        Solve();
    }
    return 0;
}