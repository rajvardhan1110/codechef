#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 998244353; 

void inputV(vector<ll> &v, ll size) {
    v.resize(size);
    for (ll i = 0; i < size; i++) {
        cin >> v[i];
    }
}

ll binExpRecur(ll a, ll b) {
    if (b == 0) return 1;
    ll res = binExpRecur(a, b / 2);
    res = (res * res) % MOD;
    if (b & 1) res = (res * a) % MOD;
    return res;
}

ll fact(ll n) {
    ll res = 1;
    for (ll i = 2; i <= n; i++) {
        res = (res * i) % MOD;
    }
    return res;
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

    vector<ll> a(n);
    inputV(a, n);

    sort(a.begin(), a.end());

    ll maxi = 1, cur = 1;
    for (ll i = 1; i < n; i++) {
        if (a[i] == a[i - 1] + 1)
            cur++;
        else {
            maxi = max(maxi, cur);
            cur = 1;
        }
    }
    maxi = max(maxi, cur);

    ll cnt = 0;
    cur = 1;
    for (ll i = 1; i < n; i++) {
        if (a[i] == a[i - 1] + 1)
            cur++;
        else {
            if (cur == maxi) cnt++;
            cur = 1;
        }
    }
    if (cur == maxi) cnt++;

    
    ll ans = cnt;
    ans = (ans * binExpRecur(2, maxi - 1)) % MOD;
    ans = (ans * fact(n - maxi)) % MOD;

    cout << ans << "\n";
}
