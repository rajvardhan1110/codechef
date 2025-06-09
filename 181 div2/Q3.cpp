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

    int n,m;
    cin>>n>>m;

    vector<vector<int>> arr(n,vector<int> (m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    int ans=0;

    for(int r=-1; r<=1; r+=2){
        for(int c=-1; c<=1; c+=2){
            map<int,int> mp;

            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    int a = arr[i][j] - r*i - c*j;

                    mp[a]++;
                }
            }

            for(auto i:mp){
                ans = max(ans,i.second);
            }
        }
    }

    cout<<n*m - ans<<endl;
}