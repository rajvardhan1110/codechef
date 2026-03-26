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

bool check(ll tarK, ll tarS, ll N, ll M) {

    if (tarS < tarK) {
        return false;
    }
    if (tarK == 0){

     return tarS == 0;
    
    }

    if (M == N) {
        return (tarS >= 1 * tarK && tarS <= (N - 1) * tarK);
    }

    if (M == 1) {
        if (N == 1) return false; 
        return (tarS >= 2 * tarK && tarS <= N * tarK);
    }

    
    ll maxi = (tarS - tarK) / M;
    
    ll num = tarS - tarK * (M - 1);
    ll den = N - M + 1;
    ll mini = 0;
    if (num > 0) {
        mini = (num + den - 1) / den; 
    }

    return max(0LL, mini) <= min(tarK, maxi);
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

    ll N, K, S, M;
    cin >> N >> K >> S >> M;

    for (ll i = 0; i <= K; i++) {
        ll remK = K - i;
        ll remS = S - (i * M);
        
        if (check(remK, remS, N, M)) {
            cout << i << endl;
            return;
        }
    }
}