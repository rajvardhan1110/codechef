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
    int n;
    cin >> n;

    vector<ll> arr(n);
    inputV(arr,n);


    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++){
        pos[arr[i]] = i;
    } 

    set<int> st;
    st.insert(-1);
    st.insert(-2);
    st.insert(n);
    st.insert(n + 1);

    ll ans = 0;

    for (int val = n; val >= 1; val--) {
        int i = pos[val];

        auto it = st.lower_bound(i);

        int r1 = *it;
        int r2 = *next(it);
        int l1 = *prev(it);
        int l2 = *prev(prev(it));

        ll cnt = 0;

        if (l1 >= 0) {
            cnt += 1LL * (l1 - l2) * (r1 - i);
        }

        if (r1 < n) {
            cnt += 1LL * (i - l1) * (r2 - r1);
        }

        ans += cnt * val;

        st.insert(i);
    }

    cout << ans << endl;
}