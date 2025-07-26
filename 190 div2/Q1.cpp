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

    ll n;
    cin>>n;

    string s;
    cin>>s;

    stack<char> st;

    // for(auto i:s){
    //     if(i=='0'){
    //         if(!st.empty() && st.top() == '1'){
    //             st.pop();
    //         }else{
    //             st.push('0');
    //         }
    //     }else{
    //         if(!st.empty() && st.top() == '0'){
    //             st.pop();
    //         }else{
    //             st.push('1');
    //         }
    //     }
    // }

    // if(!st.empty() && st.top() == '0'){
    //     cout<<"NO"<<endl;
    // }else{
    //     cout<<"YES"<<endl;
    // }


    ll inx = 0;

    while(inx < n){
        if(s[inx] == '0'){
            if(inx+1 < n && s[inx+1] == '1'){
                inx += 2;
            }else{
                cout<<"No"<<endl;
                return;
            }
        }else{
            if(inx+1 < n && s[inx+1] == '0'){
                inx += 2;
            }else{
                inx += 1;
            }
        }
    }

    cout<<"Yes"<<endl;


}