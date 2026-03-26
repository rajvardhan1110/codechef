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

ll solve1(ll i,vector<ll> &A,vector<ll> &dp) {
    if (dp[i] != -1) return dp[i];

    dp[i] = 1; 

    for (ll j = 0; j < i; j++) {
        if ((A[j] & A[i]) == A[j]) {
            dp[i] = max(dp[i], 1 + solve1(j,A,dp));
        }
    }
    return dp[i];
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

    vector<ll> arr(n);
    vector<ll> dp(n, -1);

    inputV(arr,n);
        
    sort(arr.begin(), arr.end());
       
    ll ans = 1;
    for (ll i = 0; i < n; i++) {
        ans = max(ans, solve1(i,arr,dp));
    }

    cout <<ans<<endl;
}




