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

    ll L, W;
    vector<ll> p(3);
    cin >> L >> W >> p[0] >> p[1] >> p[2];

    vector<vector<ll>> Side = {
        {L, L + W, 2 * L + W},
        {W, W + L, 2 * W + L}
    };

    int maxi = 0;

    sort(p.begin(), p.end());

    while (true) {
        ll b1 = p[0];
        ll b2 = p[0] + p[1];

        for (auto &corners : Side) {
            int cnt = 0;
            if (b1 == corners[0] || b1 == corners[1] || b1 == corners[2])
                cnt++;
            if (b2 == corners[0] || b2 == corners[1] || b2 == corners[2])
                cnt++;

            maxi = max(maxi, cnt);
        }

        if (!next_permutation(p.begin(), p.end())){
            break;
        }
           
    }

    cout << 6 - maxi << endl;
}