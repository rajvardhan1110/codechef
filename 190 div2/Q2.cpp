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

// ll solve2(ll index, vector<ll>& A, vector<ll>& B, ll x, vector<vector<ll>>& dp) {
//     if (index == A.size()) return 0;

//     if (x < A[index]) return -1;

//     if (dp[index][x] != -2) return dp[index][x];

//     ll res = -1;

    
//     if (x >= B[index]) {
//         ll parry = solve2(index + 1, A, B, x - 1, dp);
//         if (parry != -1) res = max(res, 1 + parry);
//     }

   
//     ll dodge = solve2(index + 1, A, B, x, dp);
//     if (dodge != -1) res = max(res, dodge);

//     return dp[index][x] = res;
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
}

void solve() {
    //Rajvardhan Patil

    ll n,k;
    cin>>n>>k;

    // vector<vector<ll>> dp(n,vector<ll> (k+1,-2));

    vector<ll> a(n);
    vector<ll> b(n);
    inputV(a,n);
    inputV(b,n);

    // cout<<solve2(0,A,B,k,dp)<<endl;

  
        ll s = k;
        ll p = 0;


        for(ll i = 0; i<n; i++) {
            while(p > 0 && s < a[i]) {
                --p;
                ++s;
            }

            if(s >= b[i]) {
                p++;
                s--;
            }
        }

    cout<<p<<endl;
        
}