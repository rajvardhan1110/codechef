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

    if(n == 1){
        cout<<1<<endl;
        return;
    }

    if(n == 2){
        cout<<2<<endl;
        return;
    }

    if(n&1){
        cout<<n/2 + 1 <<endl;
    }else{
        ll num = 0;

        if((n/2)&1){
            num = n/2;
        }else{
            num= (n-1) / 2;
        }

        cout<<(n/2)+(num/2 +1)<<endl;
    }
}