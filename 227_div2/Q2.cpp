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

ll solve2(ll idx, ll rem, ll N, vector<vector<ll>> &dp) {
    if(rem < 0) return -1e9;
    if(idx == N) return (rem == 0 ? 0 : -1e9);

    if(dp[idx][rem] != -1) return dp[idx][rem];

    ll best = -1e9;
    for(ll val = 1; val <= 6; val++) {
        if(val <= rem) {
            ll take = solve2(idx+1, rem - val, N, dp);
            if(take != -1e9) {
                ll maxi = (val == 6 ? 5 : 6); 
                best = max(best, maxi + take);
            }
        }
    }

    return dp[idx][rem] = best;
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
    ll N, S;
    cin >> N >> S;

    vector<vector<ll>> dp(N+1, vector<ll>(S+1, -1));

    ll ans = solve2(0, S, N, dp);
    cout << ans << endl;
}