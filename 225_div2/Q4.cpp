#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

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

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    inputV(arr, n);

    multiset<ll> s;
    for (auto x : arr) {
        s.insert(x);
    }

    ll ans = 0;

    for (ll i = 0; i < n; i++) {

        ll a = arr[i];

        auto it = s.find(a);
        if (it != s.end())
            s.erase(it);

        if (i - 1 >= 0) {
            auto it2 = s.find(arr[i - 1]);
            if (it2 != s.end())
                s.erase(it2);
        }

        if (i + 1 < n) {
            auto it3 = s.find(arr[i + 1]);
            if (it3 != s.end())
                s.erase(it3);
        }

        if (!s.empty()) {
            ll mini = *s.begin();
            ll maxi = *s.rbegin();

            ans = max(ans, abs(maxi - a));
            ans = max(ans, abs(mini - a));
        }

        if (i - 1 >= 0)
            s.insert(arr[i - 1]);

        if (i + 1 < n)
            s.insert(arr[i + 1]);

        s.insert(a);
    }

    cout << ans << endl;
}
