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

void printV(const vector<ll> &v) {
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

void dfs(ll u, ll p, const vector<vector<ll>>& adj, vector<ll>& nodeS) {
    nodeS[u] = 1;
    for (ll v : adj[u]) {
        if (v != p) {
            dfs(v, u, adj, nodeS);
            nodeS[u] += nodeS[v];
        }
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

    vector<vector<ll>> adj(n + 1);
    vector<pair<ll,ll>> edges;

    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    vector<ll> nodeS(n + 1);
    dfs(1, 0, adj, nodeS);

    ll inc = 0;

    for (ll u = 1; u <= n; ++u) {
        ll num = 1;

        for (ll v : adj[u]) {
            ll c_sz = (nodeS[v] < nodeS[u]) ? nodeS[v] : (n - nodeS[u]);
            num = (num * (c_sz + 1)) % MOD;
        }

        num = (num * 2) % MOD;
        num = (num - 1 + MOD) % MOD;

        inc = (inc + num) % MOD;
    }

    ll dec = 0;

    for (auto &e : edges) {
        ll u = e.first;
        ll v = e.second;

        ll s1 = (nodeS[u] < nodeS[v]) ? nodeS[u] : nodeS[v];
        ll s2 = n - s1;

        ll con = (s1 * s2) % MOD;
        con = (con + n) % MOD;

        dec = (dec + con) % MOD;
    }

    ll ans = (inc - dec + MOD) % MOD;

    cout << ans << endl;


}