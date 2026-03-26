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

    vector<ll> arr(2*n);
    inputV(arr,2*n);

    set<ll> seen;
    vector<ll> F, S;

    for(ll x : arr) {
        if(seen.count(x) == 0) {
            F.push_back(x);
            seen.insert(x);
        } 
        else {
            S.push_back(x);
        }
    }

    vector<ll> pos(n);
    unordered_map<ll,ll> mp;

    for(ll i = 0; i < n; i++) {
        mp[F[i]] = i + 1;
    }

    for(ll i = 0; i < n; i++) {
        pos[i] = mp[S[i]];
    }


    ll mini = n - 1;
    while(mini > 0 && pos[mini - 1] < pos[mini]) {
        mini--;
    }




    ll maxi = 1;
    while(maxi < n && pos[maxi] < pos[maxi - 1]) {
        maxi++;
    }

    if(maxi-1 >= mini) {
        cout << "Yes"<<endl;
    } 
    else {
        cout << "No"<<endl;
    }
}