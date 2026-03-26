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
    ll n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    if (n == 2 || n == 3) {
        cout << 1 << endl;
        return;
    }

    if (n == 4 || n == 6) {
        cout << 2 << endl;
        return;
    }

    if (n % 6 == 0 && n % 12 == 0) {
        ll cnt = 0;
        ll temp = n;
        while (temp != 6) {
            cnt++;
            temp /= 2;
        }
        cout << cnt << endl;
        return;
    }

    ll ans = 2e18; 

    if (n % 4 != 0) {
        cout << -1 << endl;
        return;
    }

    map<ll, ll> mp;
    vector<ll> power;
    ll num = 2;
    ll s = 1;

    while (num <= n * 4) {
        mp[num] = s;
        power.push_back(num);
        if (num > 2e18 / 2) break; 
        num *= 2;
        s++;
    }

    ll tempN = n;
    bool found = false;
    while (tempN > 0 && tempN % 4 == 0) {
        auto it = lower_bound(power.begin(), power.end(), tempN);
        
        if (it != power.end()) {
            ll val = *it;
            ll x = val - tempN;
            
            if (x % 4 == 0) {
                ll step = x / 4;
                ll actual = step + mp[val];
                ans = min(ans, actual);
                found = true;
            }
        }
        tempN /= 4; 
    }

    if (!found || ans >= 2e18) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
