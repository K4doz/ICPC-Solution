#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define MASK(x) ((1LL) << (x))
#define BIT(x, i) (((x) >> (i)) & (1LL))
#define eb emplace_back
#define pb push_back

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int INF = 1e9 + 7;
const int base = 31;
const int BL = 350;

template<class X, class Y> bool maximize(X &x, Y y) {if(x < y){x = y; return true;} return false;}
template<class X, class Y> bool minimize(X &x, Y y) {if(x > y){x = y; return true;} return false;}
void add(int &x, int y){x += y; if(x >= mod) x -= mod;}
void sub(int &x, int y){x -= y; if(x < 0) x += mod;}
int mul(int x, int y){return 1LL * x * y % mod;}
int calPw(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}
///Deruck Phung - Luong The Vinh High School For The Gifted
int p, q, r, Ans;
int pre[152][152][152], val[152][152][152], L[152];
///Code

int Get(int ii, int jj, int kk, int i, int j, int k){
    return pre[i][j][k] - pre[ii - 1][j][k] - pre[i][jj - 1][k] - pre[i][j][kk - 1] + pre[ii - 1][jj - 1][k] + pre[ii - 1][j][kk - 1] + pre[i][jj - 1][kk - 1] - pre[ii - 1][jj - 1][kk - 1];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    #define TASK "main"
    if(fopen(TASK".inp", "r")){
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }

    cin >> p >> q >> r;
    for(int j = 1; j <= q; j++)
        for(int i = 1; i <= p; i++){
            for(int k = 1; k <= r; k++){
                char c;
                cin >> c;
                pre[i][j][k] = pre[i - 1][j][k] + pre[i][j - 1][k] + pre[i][j][k - 1] - pre[i - 1][j - 1][k] - pre[i][j - 1][k - 1] - pre[i - 1][j][k - 1] + pre[i - 1][j - 1][k - 1] + (c == 'P');
            }
        }


    ///j == k
    int Ans = 0;
    for(int i = 1; i <= p; i++)
    for(int j = 1; j <= q; j++){
        int iter = 1;
        for(int k = 1; k <= r; k++){
            while(iter <= k && (j - (k - iter) < 1 || Get(i, j - (k - iter), iter, i, j, k))) iter++;
            val[i][j][k] = k - iter + 1;

           // cout << i << " " << j << " " << k << " " << val[i][j][k] << "\n";
        }
    }

    for(int j = 1; j <= q; j++)
    for(int k = 1; k <= r; k++){
        stack<int> st;
        for(int i = 1; i <= p; i++){
            while(st.size() && val[st.top()][j][k] >= val[i][j][k]) st.pop();
            if(st.size()) L[i] = st.top() + 1;
            else L[i] = 1;
            st.push(i);
        }
        while(st.size()) st.pop();

        for(int i = p; i >= 1; i--){
            int iter;
            while(st.size() && val[st.top()][j][k] >= val[i][j][k]) st.pop();
            if(st.size()) iter = st.top() - 1;
            else iter = p;

            //cout << val[i][j][k] << " " << iter - L[i] + 1 << "\n";
            Ans = max(Ans, 4 * val[i][j][k] * (iter - L[i] + 1));

            st.push(i);
        }
    }

//    cout << Ans << "\n";

    ///k == i
    for(int j = 1; j <= q; j++)
    for(int k = 1; k <= r; k++){
        int iter = 1;
        for(int i = 1; i <= p; i++){
            while(iter <= i && (k - (i - iter) < 1 || Get(iter, j, k - (i - iter), i, j, k))) iter++;
            val[i][j][k] = i - iter + 1;

            //cout << i << " " << j << " " << k << " " << val[i][j][k] << "\n";
        }
    }

    for(int i = 1; i <= p; i++)
    for(int k = 1; k <= r; k++){
        stack<int> st;
        for(int j = 1; j <= q; j++){
            while(st.size() && val[i][st.top()][k] >= val[i][j][k]) st.pop();
            if(st.size()) L[j] = st.top() + 1;
            else L[j] = 1;
            st.push(j);

//            cout << j << " " << val[i][j][k] << " " << L[j] << "\n";
        }
//        cout << "\n";
        while(st.size()) st.pop();

        for(int j = q; j >= 1; j--){
            int iter;
            while(st.size() && val[i][st.top()][k] >= val[i][j][k]) st.pop();
            if(st.size()) iter = st.top() - 1;
            else iter = q;

            Ans = max(Ans, 4 * val[i][j][k] * (iter - L[j] + 1));

            st.push(j);
        }
    }

//    cout << Ans << "\n";

    ///i == j
    for(int k = 1; k <= r; k++)
    for(int j = 1; j <= q; j++){
        int iter = 1;
        for(int i = 1; i <= p; i++){
            while(iter <= i && (j - (i - iter) < 1 || Get(iter, j - (i - iter), k, i, j, k))) iter++;
            val[i][j][k] = i - iter + 1;
        }
    }

    for(int i = 1; i <= p; i++)
    for(int j = 1; j <= q; j++){
        stack<int> st;
        for(int k = 1; k <= r; k++){
            while(st.size() && val[i][j][st.top()] >= val[i][j][k]) st.pop();
            if(st.size()) L[k] = st.top() + 1;
            else L[k] = 1;
            st.push(k);
        }
        while(st.size()) st.pop();

        for(int k = r; k >= 1; k--){
            int iter;
            while(st.size() && val[i][j][st.top()] >= val[i][j][k]) st.pop();
            if(st.size()) iter = st.top() - 1;
            else iter = k;

            Ans = max(Ans, 4 * val[i][j][k] * (iter - L[k] + 1));

            st.push(k);
        }
    }


    cout << Ans << "\n";
}
