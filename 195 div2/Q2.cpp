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

    string s;
    cin >> s;

    ll l1 = 0, r1 = n - 1, l0 = 0, r0 = n - 1;

    while (l1 < n && s[l1] != '1') l1++;
    while (r1 >= 0 && s[r1] != '1') r1--;
    while (l0 < n && s[l0] != '0') l0++;
    while (r0 >= 0 && s[r0] != '0') r0--;

    
    if (r1 == -1 || r0 == -1) {
        cout << n << endl;
        return;
    }

    
    if (l0 < l1 && r1 < r0) {
        cout << n - (r1 - l1 + 1) << endl;
        return;
    }

   
    if (l1 < l0 && r0 < r1) {
        cout << n - (r0 - l0 + 1) << endl;
        return;
    }

   
    if (l0 < l1 && l1 < r0 && r0 < r1) {
       
        ll cnt1 = 0;
        for (ll i = l0; i < l1; i++) {
            if (s[i] == '1') cnt1++;
        }

        ll cnt0 = 0;
        for (ll i = r0 + 1; i <= r1; i++) {
            if (s[i] == '0') cnt0++;
        }

        ll removed = (r0 - l1 + 1) + max(cnt0, cnt1);
        cout << n - removed + 1<< endl;
        return;
    }

    
    if (l1 < l0 && l0 < r1 && r1 < r0) {
        
        ll cnt0 = 0;
        for (ll i = l1; i < l0; i++) {
            if (s[i] == '0') cnt0++;
        }

        
        ll cnt1 = 0;
        for (ll i = r1 + 1; i <= r0; i++) {
            if (s[i] == '1') cnt1++;
        }

        ll removed = (r1 - l0 + 1) + max(cnt0, cnt1);
        cout << n - removed + 1<< endl;
        return;
    }

   
    cout << n << endl;
}
