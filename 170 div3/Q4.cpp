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

int m(vector<int> arr){
    unordered_set<int> s(arr.begin(),arr.end());

    int cont=0;

    while(s.count(cont)){
        cont++;
    }

    return cont;
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

    vector<int> arr(n);
    inputV(arr,n);

    int sum=0;

    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    sort(arr.begin(),arr.end());

    int mex=m(arr);

    int ans=sum;

    for(int i=0; i<n; i++){
        sum -= arr[i];
        ans = max(ans,sum+((i+1)*mex));
    }

    cout<<max(ans,n*n)<<endl;
}