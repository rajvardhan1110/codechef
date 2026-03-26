#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

void inputV(vector<ll> &v, ll size) {
    v.resize(size);
    for (ll i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void prllV(const vector<ll> &v) {
    for (ll val : v) {
        cout << val << " ";
    }
    cout << endl;
}

void createsieve(vector<bool> &prime, ll n) {
    prime[0] = prime[1] = false;
    for (ll i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (ll j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool PowOfTwo(ll n) {
    return n > 0 && (n & (n - 1)) == 0;
}

ll binExpRecur(ll a, ll b) {
    if (b == 0) return 1;
    ll res = binExpRecur(a, b / 2);
    if (b & 1) {
        return (a * ((res * res) % MOD)) % MOD;
    } else {
        return (res * res) % MOD;
    }
}

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    //Rajvardhan Patil
    ll n;
    cin >> n;

    vector<ll> a;
    inputV(a, n);

    ll val = abs(a[0]);
    for (ll i = 1; i < n; i++) {
        if (abs(a[i]) != val) {
            cout << "NO" <<endl;
            return;
        }
    }

    ll change = 0;

    for (ll i = 1; i < n; i++) {
        if ((a[i] >= 0 && a[i-1] < 0) ||
            (a[i] < 0 && a[i-1] >= 0)) {
            change++;
        }
    }

    if (change <= 1)
        cout << "YES"<<endl;
    else
        cout << "NO"<<endl;
}
