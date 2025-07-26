#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

const ll MOD = 1e9 + 7, MAXN = 1e6;
ll fac[MAXN + 1], inv[MAXN + 1];

template<typename T> void inputV(vector<T>& v, ll n) { v.resize(n); for (ll i = 0; i < n; ++i) cin >> v[i]; }
template<typename T> void printV(const vector<T>& v, const string& sep = " ") { for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) cout << sep; cout << *it; } cout << "\n"; }
template<typename T> T sumV(const vector<T>& v) { return accumulate(all(v), (T)0); }
template<typename T> T maxV(const vector<T>& v) { return *max_element(all(v)); }
template<typename T> T minV(const vector<T>& v) { return v.empty() ? numeric_limits<T>::max() : *min_element(all(v)); }
template<typename T> T secmaxV(const vector<T>& v) { if (v.size() < 2) return -1; T m = maxV(v), s = numeric_limits<T>::min(); bool f = false; for (const T& x : v) if (x != m) { s = max(s, x); f = true; } return f ? s : -1; }

ll gcd(ll a, ll b) { return __gcd(a, b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
bool isPrime(ll n) { if (n <= 1) return false; for (ll i = 2; i * i <= n; i++) if (n % i == 0) return false; return true; }
bool powerOfTwo(ll n) { return n > 0 && (n & (n - 1)) == 0; }
bool even(ll n) { return n % 2 == 0; }
bool odd(ll n) { return n % 2 != 0; }

ll modExp(ll b, ll e, ll m) { b %= m; ll r = 1; while (e > 0) { if (e & 1) r = (r * b) % m; b = (b * b) % m; e >>= 1; } return r; }

void factorial() { fac[0] = 1; for (ll i = 1; i <= MAXN; i++) fac[i] = (fac[i - 1] * i) % MOD; }
void inverses() { inv[MAXN] = modExp(fac[MAXN], MOD - 2, MOD); for (ll i = MAXN; i > 0; i--) inv[i - 1] = (inv[i] * i) % MOD; }
ll ncr(ll n, ll r) { if (r < 0 || r > n) return 0; return fac[n] * inv[r] % MOD * inv[n - r] % MOD; }

ll get_hash(const string& s) { ll h = 0; for (char c : s) h = (h * 31 + (c - 'a' + 1)) % MOD; return h; }



bool check (ll mid, vector <ll> &a, vector <ll>& b) {
    
    ll extra = 0;
    ll req = 0;

    for(ll i = 0; i < a.size(); i++) {

        if (mid - (a[i] + b[i]) >= 0) {
            extra += ((mid - (a[i] + b[i])) / 2);
        }
        else {
            req += ((a[i] + b[i]) - mid);
        }
    }

    if (extra >= req) return true;
    return false;

}

void solve() {
    
    ll n;
    cin >> n;

    vector <ll> a(n);
    inputV(a, n);

    vector <ll> b(n);
    inputV(b, n);

    ll high = INT_MIN;


    ll sum = accumulate(b.begin(), b.end(), 0LL);

    for(ll i=0; i<n; i++){
        ll into2 = sum - b[i];
        ll check = a[i]+b[i] + 2*into2;

        high = max(high,check);
    }

    


    ll low = maxV(a);


    ll ans = 1e10;

    while (low <= high) {

        ll mid = low + (high - low) / 2;

        if (check(mid, a, b)) {
            ans = min (ans, mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}