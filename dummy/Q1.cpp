#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;

    if (m <= n) {
        if (m == 1) {
            cout << 1 << " " << 2 << endl;
        } else {
            cout << m - 1 << " " << m << endl;
        }

        return;
    } 

    for (ll k = 2; k <= 30; k++) {
        ll den = (1LL << k) - 2;  // 2^k - 2

        for (ll y = 2; y <= n; y++) {
            if ((m - y) % den != 0) continue;

            ll d = (m - y) / den;
            ll x = y - d;

            if (d > 0 && x >= 1 && x < y) {
                cout << x << " " << y << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}