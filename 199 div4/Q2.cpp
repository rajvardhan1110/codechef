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


    ll n;
    cin>>n;

    vector<ll> arr(n);

    inputV(arr,n);

    ll ans = 0;

    ll maxi = arr[0];

    for(ll i =1; i<n; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
            ans = i;
        }
    }

    cout<<ans+1<<endl;
}