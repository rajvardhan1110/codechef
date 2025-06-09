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
    cin>>n;

    vector<int> A(n);
    vector<int> B(n);

    inputV(A,n);
    inputV(B,n);

    
    int ans=-1;

    for(int i=0; i<n; i++){

        vector<pair<int,int>> pa(n);
        int p=A[i];
        for(int j=0; j<n; j++){
            pa[j]={abs(A[j]-p),A[j]};
        }

        sort(pa.begin(),pa.end());
        bool cheak=true;

        for(int j=0; j<n; j++){

            if(pa[j].second!=B[j]){
                cheak=false;
                break;
            }

        }

        if(cheak){
            ans=i+1;
            break;
        }
    }

    cout<<ans<<endl;
}