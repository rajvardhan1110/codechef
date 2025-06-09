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

int bit(int num){
    int mk=0;
    while(num){
        mk += num&1;
        num >>=1;
    }

    return mk;
}

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

    map<int,vector<int>> same;
    map<int,vector<int>> region;

    for(int i=0; i<n; i++){
        int count = bit(arr[i]);

        same[count].push_back(arr[i]);
        region[count].push_back(i);


    }

    for(auto grp:same){
        vector<int>& group = grp.second;
        vector<int>& pos= region[grp.first];

        vector<int> cheack;
        for(auto i:pos){
            cheack.push_back(i+1);
        }

        sort(group.begin(),group.end());
        sort(cheack.begin(),cheack.end());

        if(group != cheack){
            cout<<"No"<<endl;
            return;
        }

        
    }

    cout<<"Yes"<<endl;
}