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



// ll dfs(ll i, ll k, ll x, const vector<ll> &A, vector<vector<vector<ll>>> &dp) {
//     ll N = A.size();
//     if (k < 0) return LLONG_MIN / 2;
//     if (i == N) return 0;

//     if (dp[i][k][x] != LLONG_MIN) return dp[i][k][x];

//     ll res = dfs(i + 1, k, x, A, dp); 

//     if (k >= 1)
//         res = max(res, A[i] + dfs(i + 1, k - 1, x + 1, A, dp));

//     if (k >= 2)
//         res = max(res, A[i] + x + dfs(i + 1, k - 2, x + 1, A, dp));

//     return dp[i][k][x] = res;
// }

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> A;
    inputV(A, N);
    sort(A.rbegin(), A.rend());

    // ll maxK = 2 * N;
    // vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(maxK + 1, vector<ll>(N + 1, LLONG_MIN)));

    // for (ll k = 1; k <= maxK; k++) {
    //     cout << dfs(0, k, 0, A, dp) << " ";
    // }
    // cout << "\n";

    vector<ll> arr(N);
    arr[0] = A[0];

    for(ll i = 1; i<N; i++){
        arr[i] = arr[i-1] + A[i];
    }

    for(ll k = 1; k<=2*N; k++){
        ll c1 = k;
        ll c2 = 0;

        ll ans = 0;

        while(c1 >= 0){
            if(c1+c2 > N){
                c1 -= 2;
                c2++;

                continue;
            }

            ll subsum = arr[c1+c2-1] + (c2 * (2*c1 + c2-1)) / 2;

            ans = max(ans,subsum);

            c1 -= 2;
            c2++;
        }

        cout<<ans<<" ";

    }

    cout<<endl;
}