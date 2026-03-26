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

ll solve2(ll i,ll type, vector<ll>& a, vector<ll>& b,vector<vector<ll>>& dp){
    if(i == a.size()){
        return 0;
    }

    if(dp[i][type] != -1){
        return dp[i][type];
    }

    ll ans = 0;

    if(type == 0){
        ans = max(ans,1+solve2(i+1,1,a,b,dp));
        ans = max(ans,1+solve2(i+1,2,a,b,dp));
    }

    if(type == 1){
        if(a[i-1] < a[i]) ans = max(ans,1+solve2(i+1,1,a,b,dp));
        if(a[i-1] < b[i]) ans = max(ans,1+solve2(i+1,2,a,b,dp));
    }

    if(type == 2){
        if(b[i-1] < a[i]) ans = max(ans,1+solve2(i+1,1,a,b,dp));
        if(b[i-1] < b[i]) ans = max(ans,1+solve2(i+1,2,a,b,dp));
    }

    dp[i][type] = ans;
    return ans;
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
    cin>>n;

    vector<ll> a(n);
    vector<ll> b(n);
    inputV(a,n);
    inputV(b,n);

    vector<vector<ll>> dp(n+1,vector<ll> (3,-1));

    ll ans = 0;

    for(ll i = 0; i<n; i++){
        ans += solve2(i,0,a,b,dp);
    }

    cout<<ans<<endl;




}