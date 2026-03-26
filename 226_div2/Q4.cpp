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
    //Rajvardhan Patil

    ll n;
    cin >> n;

    vector<ll> arr(n);
    inputV(arr, n);

    map<ll,ll> mp;

    for (auto x : arr) {
        mp[x]++;
    }

    vector<ll> con;   

    for (auto it : mp) {
        con.push_back(it.first);
    }

    ll cs = con.size();
    vector<ll> r(n + 1, 0);   

    
    for (ll i = 0; i < cs - 1; i++) {
        r[con[i]] = con[i + 1];
        mp[con[i + 1]]--;
    }

    r[con[cs - 1]] = con[0];
    mp[con[0]]--;
    

    ll p = 1;
    for (ll i = 1; i <= n; i++) {
        if (r[i] == 0) {
            while (mp[p] == 0) p++;
            r[i] = p;
            mp[p]--;
        }
    }

    for (ll i = 1; i <= n; i++) {
        cout << r[i] << " ";
    }
    cout << endl;
}