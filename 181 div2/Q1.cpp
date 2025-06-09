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

    int n;
    cin >> n;

    vector <int> v(n);
    inputV(v,n);

    // unordered_map <int,int> mpp;

    // for (auto i : v) {
    //     mpp[i]++;
    // }

    // for (int i = 0; i < n; i++) {
    //     if (!mpp.count(2 * v[i])) {
    //         cout << v[i] << " " << v[i] << "\n";
    //         return;
    //     }
    // }
    // cout << -1 << "\n";
    // return ;

    sort(v.begin(), v.end());
    if(v[0] < 0){
        cout<<v[0]<<" "<<v[0]<<endl;
        return;
    }

    int i=n-1;

    while(i>=0 && v[i]==0){
        i--;

        if(i==-1){
            cout<<-1<<endl;
            return;
        }
    }

    

    cout<<v[i]<<" "<<v[i]<<endl;
    

}