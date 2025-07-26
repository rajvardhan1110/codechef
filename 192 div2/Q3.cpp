#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007;

void inputV(vector<ll> &v, int size) {
    v.resize(size);
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void printV(const vector<ll> &v) {
    for (ll val : v) {
        cout << val << " ";
    }
    cout << endl;
}

void createsieve(vector<bool> &prime, int n) {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (int j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool ok(vector<ll> &prefixx) {
    for (ll i : prefixx) {
        if (i % 3 == 0) {
            return false;
        }
    }
    return true;
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

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    inputV(v, n);

    vector<ll> prefixx(n);
    prefixx[0] = v[0];
    for (ll i = 1; i < n; i++) {
        prefixx[i] = prefixx[i - 1] + v[i];
    }

    if (ok(prefixx)) {
        cout << "YES\n";
        return;
    }

    vector<ll> s(n);
    s[n - 1] = v[n - 1];
    for (ll i = n - 2; i >= 0; i--) {
        s[i] = s[i + 1] + v[i];
    }

    ll x = -1;
    for (ll i = n - 1; i >= 0; i--) {
        if (prefixx[i] % 3 == 0) {
            x = i;
            break;
        }
    }

    if (ok(s)) {
        cout << "YES\n";
        return;
    }

    for (ll i = x + 1; i < n; i++) {
        bool f = true;
        for (ll j = i - 1; j >= 0; j--) {
            if ((s[j] - s[i]) % 3 == 0) {
                f = false;
                break;
            }
        }

        if (f) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
