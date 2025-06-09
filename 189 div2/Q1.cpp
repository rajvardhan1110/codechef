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

    ll n,k;
    cin>>n>>k;

    vector<ll> a(n);
    vector<ll> b(n);

    inputV(a,n);
    inputV(b,n);

    map<ll,ll> mp;

    for(ll i=0; i<n; i++){
        if (mp.count(a[i])) {
        // key is present

        mp[a[i]] = min(mp[a[i]],b[i]);

    } else {
     // key is not present

     mp[a[i]] = b[i];
    }

    }

    vector<ll> temp;

    for(auto i:mp){
        temp.push_back(i.second);
    }

    sort(temp.begin(),temp.end());

    ll sum = 0;
    ll ans = 0;

    for(ll i=0; i<temp.size(); i++){
        sum += temp[i];

        ll a = k*(i+1) - sum;

        ans = max(ans,a);
    }

    cout<<ans<<endl;


}