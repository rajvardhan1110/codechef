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

    ll n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;

    // if(n % 2 == 0){
    //     ll z = n/2;
    //     ll o = n/2;

    //     if(c>=d){
    //         cout<<z*a + o*b + (z*o)*c<<endl;
    //     }else{
    //         cout<<z*a + o*b + (z*o)*d<<endl;
    //     }
    // }else{
    //     if(a >=b){
    //         ll z = n/2 + 1;
    //         ll o = n/2;

    //         if(c>=d){
    //             cout<<z*a + o*b + (z*o)*c<<endl;
    //         }else{
    //             cout<<z*a + o*b + (z*o)*d<<endl;
    //         }
    //     }else{
    //         ll z = n/2 ;
    //         ll o = n/2 + 1;

    //         if(c>=d){
    //             cout<<z*a + o*b + (z*o)*c<<endl;
    //         }else{
    //             cout<<z*a + o*b + (z*o)*d<<endl;
    //         }
    //     }
    // }
    ll ans = 0;
    if(c >= d){
        for(ll zero = 0; zero<=n; zero++){
            ans = max(ans,zero*a + (n-zero)*b + zero*(n-zero)*c);
        }
    }else{
        for(ll zero = 0; zero<=n; zero++){
            ans = max(ans,zero*a + (n-zero)*b + zero*(n-zero)*d);
        }
    }

    cout<<ans<<endl;
}