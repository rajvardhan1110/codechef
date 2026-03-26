#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void inputV(vector<ll> &v, int size) {
    v.resize(size);
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

ll solve2(ll i, ll prev, vector<ll> &arr, vector<vector<ll>> &dp) {
    ll n = arr.size();

    if (i >= n) return 0;

    if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

    ll take = 0, skip = 0;

    if (prev == -1) {
        take = 1 + solve2(i + 1, i, arr, dp);  
        skip = solve2(i + 1, -1, arr, dp);     
    } else {
        if ((arr[i] % 2) != (arr[prev] % 2)) {
            take = 1 + solve2(i + 1, i, arr, dp);
        }
        skip = solve2(i + 1, prev, arr, dp);
    }

    return dp[i][prev + 1] = max(take, skip);
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr;
    inputV(arr, n);

   
    vector<vector<ll>> dp(n, vector<ll>(n + 1, -1));

    cout << solve2(0, -1, arr, dp) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
