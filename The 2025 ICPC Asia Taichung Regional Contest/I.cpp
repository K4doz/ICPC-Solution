/*
    Author: Cadocx
    Codeforces: https://codeforces.com/profile/Kadoc
    VNOJ: oj.vnoi.info/user/Cadoc
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
#define bit(n, i) (((n) >> (i)) & 1)
#define set_on(n, i) ((n) | mask(i))
#define set_off(n, i) ((n) & ~mask(i))
//constant
#define N 200005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define base 31
#define Kadoc 0
#ifndef EPS
#define EPS 1e-6
#endif
const double PI = acos(-1.0l);
#define double long double

int n, r;

inline int cmp(double a, double b) {
    return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);
}

template<typename T>
struct P {
    T x, y;
    P() { x = y = T(0); }
    P(T _x, T _y) : x(_x), y(_y) {}

    P operator + (const P& a) const { return P(x+a.x, y+a.y); }
    P operator - (const P& a) const { return P(x-a.x, y-a.y); }
    P operator * (T k) const { return P(x*k, y*k); }
    P<double> operator / (double k) const { return P(x/k, y/k); }

    T operator * (const P& a) const { return x*a.x + y*a.y; }
    T operator % (const P& a) const { return x*a.y - y*a.x; }

    int cmp(const P<T>& q) const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }

    #define Comp(x) bool operator x (const P& q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
    #undef Comp

    T norm() { return x*x + y*y; }

    // Note: There are 2 ways for implementing len():
    // 1. sqrt(norm()) --> fast, but inaccurate (produce some values that are of order X^2)
    // 2. hypot(x, y) --> slow, but much more accurate
    double len() { return hypot(x, y); }

    P<double> rotate(double alpha) {
        double cosa = cos(alpha), sina = sin(alpha);
        return P(x * cosa - y * sina, x * sina + y * cosa);
    }
};
using Point = P<double>;

template<typename T>
T area2(P<T> a, P<T> b, P<T> c) { return a%b + b%c + c%a; }

template<typename T>
void ConvexHull(vector<P<T>> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<P<T>> up, dn;
    for (int i = 0; i < (int) pts.size(); i++) {
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

template<typename T>
istream& operator >> (istream& cin, P<T>& p) {
    cin >> p.x >> p.y;
    return cin;
}
template<typename T>
ostream& operator << (ostream& cout, const P<T>& p) {
    cout << p.x << ' ' << p.y;
    return cout;
}

double angle(Point a, Point b) { // min of directed angle AOB & BOA
    return acos((a * b) / sqrt(a.norm()) / sqrt(b.norm()));
}

double area(Point A, Point B) {
    return abs((A.x * B.y - B.x * A.y) / 2.0);
}

struct Line {
    double a, b, c;
    Point A, B;

    Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {} 

    Line(Point _A, Point _B) : A(_A), B(_B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = - (a * A.x + b * A.y);
    }
    Line(Point P, double m) {
        a = -m; b = 1;
        c = -((a * P.x) + (b * P.y));
    }
    double f(Point p) {
        return a*p.x + b*p.y + c;
    }
};
ostream& operator << (ostream& cout, const Line& l) {
    cout << l.a << "*x + " << l.b << "*y + " << l.c;
    return cout;
}

struct Circle : Point {
    double r;
    Circle(double _x = 0, double _y = 0, double _r = 0) : Point(_x, _y), r(_r) {}
    Circle(Point p, double _r) : Point(p), r(_r) {}
    
    bool contains(Point p) { return (*this - p).len() <= r + EPS; }

    double area() const { return r*r*PI; }

    // definitions in https://en.wikipedia.org/wiki/Circle
    // assumption: 0 <= theta <= 2*PI
    // theta: angle in radian
    double sector_area(double theta) const {
        return 0.5 * r * r * theta;
    }

    // assumption: 0 <= theta <= 2*PI
    // theta: angle in radian
    double segment_area(double theta) const {
        return 0.5 * r * r * (theta - sin(theta));
    }
};
istream& operator >> (istream& cin, Circle& c) {
    cin >> c.x >> c.y >> c.r;
    return cin;
}
ostream& operator << (ostream& cout, const Circle& c) {
    cout << '(' << c.x << ", " << c.y << ") " << c.r;
    return cout;
}

vector<Point> intersection(Line l, Circle cir) {
    double r = cir.r, a = l.a, b = l.b, c = l.c + l.a*cir.x + l.b*cir.y;
    vector<Point> res;

    double x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b);
    if (c*c > r*r*(a*a+b*b)+EPS) return res;
    else if (fabs(c*c - r*r*(a*a+b*b)) < EPS) {
        res.push_back(Point(x0, y0) + Point(cir.x, cir.y));
        return res;
    } else {
        double d = r*r - c*c/(a*a+b*b);
        double mult = sqrt (d / (a*a+b*b));
        double ax,ay,bx,by;
        ax = x0 + b * mult;
        bx = x0 - b * mult;
        ay = y0 - a * mult;
        by = y0 + a * mult;

        res.push_back(Point(ax, ay) + Point(cir.x, cir.y));
        res.push_back(Point(bx, by) + Point(cir.x, cir.y));
        return res;
    }
}

template<typename T>
int ccw(P<T> a, P<T> b, P<T> c) {
    return cmp((b-a)%(c-a), T(0));
}

void solve(){
    cin >> n >> r;

    vector<P<ll>> vec;
    FOR(i, 1, n){
        ll x, y; cin >> x >> y;
        vec.eb(x, y);
    }

    ConvexHull(vec);
    double S_hinhtron = PI * r * r;

    if(sz(vec) == 0){
        cout << fixed << setprecision(12) << 0.0 << '\n';
        return;
    }
    if(sz(vec) == 1){
        cout << fixed << setprecision(12) << S_hinhtron/2.0 << '\n';
        return;
    }
    if(sz(vec) == 2){
        cout << fixed << setprecision(12) << S_hinhtron/2.0 << '\n';
        return;
    }

    double Ans = 0;
    FOR(i, 0, sz(vec)-1){
        P<ll> p1 = vec[i], p2 = vec[(i+1) % sz(vec)], p3 = vec[0];
        if(i == 0 || i == sz(vec)-1) p3 = vec[2];

        ll a = p1.y - p2.y;
        ll b = p2.x - p1.x;
        ll c = -a * p1.x -b * p1.y;

        Point A, B;
        vector<Point> inter = intersection(Line(a, b, c), Circle(0, 0, r));
        A = inter[0], B = inter[1];

        double S_cal = angle(A, B) * r * r / 2.0 - area(A, B);

        int AOB = ccw(p1, P<ll>(0, 0), p2), ACB = ccw(p1, p3, p2);
        if(AOB == 0 || AOB + ACB == 0){
            S_cal = S_hinhtron / 2.0;
        }
        Ans = max(Ans, min(S_cal, S_hinhtron - S_cal));
    }

    cout << fixed << setprecision(12) << Ans;
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