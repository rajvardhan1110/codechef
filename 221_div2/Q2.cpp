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

    ll N;
    cin >> N;

    if (N % 2 == 1) {
        cout << 0 << endl;
        return;
    }

    vector<ll> digits;
    ll temp = N;
    while (temp > 0) {
        digits.push_back(temp % 10);
        temp /= 10;
    }

    if (digits.empty()) {
        cout << -1 << endl;
        return;
    }

    bool hasOdd = false;
    for (ll d : digits) {
        if (d & 1) {
            hasOdd = true;
            break;
        }
    }
    if (hasOdd) {
        cout << 1 << endl;
        return;
    }

    if (digits.size() == 1) {
        cout << -1 << endl;
        return;
    }

    ll LD = digits[0]; 
    bool B = false;

    for (ll d : digits) {
        if (d > LD) {
            B = true;
            break;
        }
    }

    if (B)
        cout << 2 << endl;
    else
        cout << 3 << endl;
}