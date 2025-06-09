#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007;

vector<bool> prime(200001, true); // global prime vector

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

    createsieve(prime, 200001); // Call sieve once

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> primes, composites;

    for (ll i = 1; i <= n; ++i) {
        if (prime[i]) {
            primes.push_back(i);
        } else {
            composites.push_back(i);
        }
    }

    vector<ll> ans(n + 1, -1);
    ans[n] = 2; 

    int idx = 0;
    for (ll p : primes) {
        if (p == 2) continue;
        if (idx >= n) break;
        ans[idx] = p;
        idx += 2;
    }

    idx = 1;
    for (ll c : composites) {
        if (idx >= n) break;
        ans[idx] = c;
        idx += 2;
    }

    for(ll i = 0; i<ans.size(); i++){
        if(ans[i] != -1){
            cout<<ans[i]<<" ";
        }
    }

    cout<<endl;
}
