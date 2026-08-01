/*
    The 2025 Asia Yokohama Regional Contest - Problem H
*/


#include<bits/stdc++.h>
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FORD(i, l, r) for (int i = l; i >= r; i--)
#define ll long long 
const int N = 2e5 + 5;
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen("task.inp", "r")){
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }

    string t;
    cin >> t;

    if (t[0] >= '2') {

        char c = t[0];
        c--;
        cout << c;
        for (int i = 1; i < t.size(); i++)
            cout << t[i];
        cout << '1';
        for (int i = 1; i < t.size(); i++)
            cout << 0;
    }
    else {
        if (t[1] == '0') {
            cout << 9;
            for (int i = 2; i < t.size(); i++)
                cout << t[i];

            cout << 1;
            for (int i = 2; i < t.size(); i++)
                cout << 0;
        }
        else {
            for (int i = 1; i < t.size(); i++)
                cout << t[i];
            cout << 1;
            for (int i = 1; i < t.size(); i++)
                cout << 0;

        }
    }




    
}