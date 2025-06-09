#include <bits/stdc++.h>
using namespace std;
#define int long long

void inputV(vector<int> &v, int size) {
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void printV(vector<int> &v, int size) {
    for (int i = 0; i < size; i++) {
        cout << v[i];
    }
}

void createsieve(vector<bool> &prime, int n) {
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool PowOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

void solve();

int32_t main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

void solve() {
    // Add your code here

    int x,y;
    cin>>x>>y;

    int ans=0;
    int pw=0;

    int h=x/2;

    for(int i=0; i<h; i++){
        ans += pow(10,pw);
        pw++;
    }

    for(int i=0; i<y; i++){
         ans += 2*pow(10,pw);
         pw++;
    }

    for(int i=0; i<h; i++){
         ans += pow(10,pw);
         pw++;
    }

   
    cout<<ans<<endl;




}