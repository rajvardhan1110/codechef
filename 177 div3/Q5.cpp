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

    string a;
    string b;

    cin>>a;
    cin>>b;

    // int ans[2010][3];

    vector<pair<int,pair<int,int>>> ans(2020);
    int count=0;

    int i=0;

    while(i<n){

        if(a[i]==b[i]){
            i++;
            continue;
        }

        int ini=i;

        while(i<n && a[i]!=b[i]){
            i++;
        }

        int end=i-1;

        ans[count].first=1;
        ans[count].second={ini+1,end+1};

        count++;
    }

    cout<<count<<endl;

    for(int i=0; i<count; i++){
        cout<<ans[i].first<<" ";
        cout<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
    }

}